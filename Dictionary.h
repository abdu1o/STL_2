#pragma once
class Dictionary
{
private:

	map<string, string> dictionary;
    string _word;
    string _trans;

public:

    void Add(string word, string trans)
    {
        this->_word = word;
        this->_trans = trans;
        this->dictionary[word] = trans;
    }

    void Search(string word) 
    {
        auto it = dictionary.find(word);
        if (it == dictionary.end()) 
        {
            cout << "Word is not found" << endl;
        }
        else 
        {
            cout << "Your word: " << word << endl;
            cout << "Translation: " << it->second << endl;
        }
    }

    void Remove(string word) 
    {
        auto it = dictionary.find(word);
        if (it == dictionary.end()) 
        {
            cout << "Word is not found" << endl;
        }
        else 
        {
            dictionary.erase(it);
        }
    }

    void Edit(string old_word, string new_word, string new_trans) 
    {
        auto it = dictionary.find(old_word);
        if (it == dictionary.end()) 
        {
            cout << "Word is not found" << std::endl;
        }
        else
        {
            dictionary.erase(it);
            dictionary.insert_or_assign(new_word, new_trans);
        }
    }

    void Read(string data)
    {
        dictionary.clear();

        ifstream file(data);
        if (!file.is_open()) 
        {
            cout << "File is not open" << endl;
            return;
        }

        else
        {
            string word, trans;
            while (file >> word >> trans)
            {
                dictionary[word] = trans;
            }
        }
        
        file.close();
    }

    void Save(string data)
    {
        ofstream file(data); 
        if (!file.is_open() || dictionary.empty()) 
        {
            cout << "Saving is not possible" << endl;
            return;
        }
        
        else
        {
            for (const auto& pair : dictionary)
            {
                file << pair.first << ": " << pair.second << endl;
            }
        }
        
        file.close();
    }

    void Print()
    {
        for (const auto& pair : dictionary) 
        {
            cout << pair.first << ": " << pair.second << endl;
        }
    }
};