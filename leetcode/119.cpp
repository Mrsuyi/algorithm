
class Solution {
public:
	vector<vector<int>> cache = { { 1 }, { 1, 1 }, { 1, 2, 1 } };

	vector<int> getRow(int rowIndex)
	{
		if (rowIndex >= cache.size())
		{
			for (int i = cache.size() - 1; i < rowIndex; i++)
			{
				vector<int> line = { 1 };

				auto i_pre = cache[i].begin();

				for (; *(i_pre + 1) > *i_pre; i_pre++)
				{
					line.push_back(*i_pre + *(i_pre + 1));
				}

				int j = line.size() - 1;

				if (*i_pre == *(i_pre + 1))
				{
					line.push_back(*i_pre * 2);
				}

				for (; j >= 0; j--)
				{
					line.push_back(line[j]);
				}

				cache.push_back(line);
			}
		}

		return cache[rowIndex];
	}
};