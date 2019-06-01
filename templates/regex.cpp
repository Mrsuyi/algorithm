#include <iostream>
#include <memory>
#include <unordered_set>
#include <vector>

using namespace std;

#pragma mark - Node

struct Node {
  enum Type {
    CAT = 0,
    OR,
    STAR,
    CHAR,
    END,
  };

  Node(Type type, char c = '\0', int idx = -1)
      : type(type), left(nullptr), right(nullptr), chr(c), idx(idx) {}

  // Calculate firstpos, lastpos, followpos.
  void calc();
  bool nullable() const;

  // Only for test purpose:
  // Recover regex pattern.
  string print_pattern() const;
  // Print NFA.
  void print_nfa() const;

  Type type;
  Node* left;
  Node* right;
  char chr;
  int idx;
  unordered_set<Node*> firstpos;
  unordered_set<Node*> lastpos;
  unordered_set<Node*> followpos;
};

std::string Node::print_pattern() const {
  switch (type) {
    case CAT:
      assert(left);
      assert(right);
      return left->print_pattern() + right->print_pattern();
    case OR:
      assert(left);
      assert(right);
      return left->print_pattern() + '|' + right->print_pattern();
    case STAR: {
      assert(left);
      assert(!right);
      string sub = left->print_pattern();
      if (sub.size() > 1) {
        return "(" + sub + ")*";
      } else {
        return sub + "*";
      };
    }
    case CHAR:
      return string(1, chr);
    case END:
      return "";
  }
  assert(false);
  return "";
}

bool Node::nullable() const {
  switch (type) {
    case STAR:
      return true;
    case OR:
      return left->nullable() || right->nullable();
    case CAT:
      return left->nullable() && right->nullable();
    case CHAR:
    case END:
      return true;
  }
  assert(false);
  return true;
}

void Node::calc() {
  if (left)
    left->calc();
  if (right)
    right->calc();

  switch (type) {
    case CHAR:
    case END: {
      firstpos.insert(this);
      lastpos.insert(this);
      break;
    }
    case STAR: {
      firstpos = left->firstpos;
      lastpos = right->lastpos;
      // followpos.
      for (Node* last : lastpos) {
        for (Node* first : firstpos) {
          first->followpos.insert(last);
        }
      }
      break;
    }
    case CAT: {
      // firstpos.
      for (Node* first : left->firstpos) {
        firstpos.insert(first);
      }
      if (left->nullable()) {
        for (Node* first : right->firstpos) {
          firstpos.insert(first);
        }
      }
      // lastpos.
      for (Node* last : right->lastpos) {
        lastpos.insert(last);
      }
      if (right->nullable()) {
        for (Node* last : left->lastpos) {
          lastpos.insert(last);
        }
      }
      // followpos.
      for (Node* r : right->firstpos) {
        for (Node* l : left->lastpos) {
          l->followpos.insert(r);
        }
      }
      break;
    }
    case OR: {
      // firstpos.
      for (Node* first : left->firstpos) {
        firstpos.insert(first);
      }
      for (Node* first : right->firstpos) {
        firstpos.insert(first);
      }
      // lastpos.
      for (Node* first : left->firstpos) {
        firstpos.insert(first);
      }
      for (Node* first : right->firstpos) {
        firstpos.insert(first);
      }
      break;
    }
  }
}

#pragma mark - Tree

struct Tree {
  Tree(const string& pattern);
  ~Tree();

  // Eat as much as possible until ')' or end.
  Node* eat();
  // Try to eat a '*'.
  Node* eat_star(Node* cur);

  Node* root;
  vector<Node*> nodes;
  const string pattern;
  size_t idx;
};

Tree::Tree(const string& pattern) : root(nullptr), pattern(pattern), idx(0) {
  root = eat();
}

Tree::~Tree() {
  for (size_t i = 0; i < nodes.size(); ++i)
    delete nodes[i];
}

Node* Tree::eat() {
  // printf("eat\n");
  Node* pre = nullptr;
  while (idx < pattern.size()) {
    // printf("%zu\n", idx);
    if (pattern[idx] == ')') {
      // printf("exit\n");
      return pre;
    }

    Node* cur = nullptr;
    // pre|cur.
    if (pattern[idx] == '|') {
      ++idx;
      // "null|".
      Node* nxt = eat();
      if (pre) {
        cur = new Node(Node::OR);
        nodes.push_back(cur);
        cur->left = pre;
        cur->right = nxt;
        pre = cur;
      } else {
        pre = nxt;
      }
    }
    // pre&cur.
    else {
      // ().
      if (pattern[idx] == '(') {
        ++idx;
        cur = eat();
        assert(pattern[idx] == ')');
        ++idx;
      }
      // normal char.
      else {
        cur = new Node(Node::CHAR, pattern[idx], idx);
        ++idx;
      }
      cur = eat_star(cur);

      if (pre) {
        Node* cat = new Node(Node::CAT);
        nodes.push_back(cat);
        cat->left = pre;
        cat->right = cur;
        pre = cat;
      } else {
        pre = cur;
      }
    }
  }
  // null pattern.
  if (!pre)
    return nullptr;
  Node* end = new Node(Node::END);
  nodes.push_back(end);
  Node* cat = new Node(Node::CAT);
  nodes.push_back(cat);
  cat->left = pre;
  cat->right = end;
  return cat;
}

Node* Tree::eat_star(Node* cur) {
  if (idx == pattern.size() || pattern[idx] != '*') {
    return cur;
  }
  ++idx;
  // Ignore "()*".
  if (!cur)
    return nullptr;
  Node* star = new Node(Node::STAR);
  nodes.push_back(star);
  star->left = cur;
  return star;
}

#pragma mark - Regex

struct Regex {
  Regex(const string& pattern);
};

int main() {
  assert(Tree("a|b").root->print_pattern() == "a|b");
  assert(Tree("(a|b)*abb").root->print_pattern() == "(a|b)*abb");

  return 0;
}
