#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Node {
  enum Type {
    CAT = 0,
    OR,
    STAR,
    CHAR,
    END,
  };

  Node(Type type, char c = '\0')
      : type(type), left(nullptr), right(nullptr), chr(c) {}

  bool nullable() const { return type == STAR; }

  // Only for test purpose.
  string print() const {
    switch (type) {
      case CAT:
        assert(left);
        assert(right);
        return left->print() + right->print();
      case OR:
        assert(left);
        assert(right);
        return left->print() + '|' + right->print();
      case STAR: {
        assert(left);
        assert(!right);
        string sub = left->print();
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

  Type type;
  Node* left;
  Node* right;
  char chr;
  vector<Node*> firstpos;
  vector<Node*> lastpos;
  vector<Node*> followpos;
};

struct Tree {
  Tree(const string& pattern);
  ~Tree();

  // Match as much as possible until ')' or end.
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
        cur = new Node(Node::CHAR, pattern[idx]);
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

struct Regex {
  Regex(const string& pattern);
};

int main() {
  assert(Tree("a|b").root->print() == "a|b");
  assert(Tree("(a|b)*abb").root->print() == "(a|b)*abb");

  return 0;
}
