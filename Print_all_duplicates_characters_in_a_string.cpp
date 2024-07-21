void printDups(string str)
{
    unordered_map<char, int> mpp;
    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i]]++;
    }

    for (auto it : mpp)
    {
        if (it.second > 1)
        cout << it.first << ":" << it.second<< endl;
    }
}