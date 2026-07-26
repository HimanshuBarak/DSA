# Trie with Top-3 Autocomplete Suggestions (C++)

This implementation supports:

- Insert a word with a popularity score
- Search for a complete word
- Check if a prefix exists
- Return all words matching a prefix (DFS)
- Return the **Top 3 most popular** words for a prefix in **O(length of prefix)**

## Idea

Instead of performing a DFS every time autocomplete is requested, every Trie node stores the **top 3 most popular words** that pass through that node.

While inserting a word, every node along its path updates its `top3` list.

This makes autocomplete extremely fast.

---

## Time Complexity

| Operation | Complexity |
|-----------|------------|
| Insert | O(L) |
| Search | O(L) |
| StartsWith | O(L) |
| Autocomplete (DFS) | O(Number of matching words) |
| Top-3 Autocomplete | O(L) |

where **L** is the length of the word/prefix.

---

## C++ Implementation

```cpp
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class TrieNode {
public:
    TrieNode* children[26];
    bool isWordEnd;
    int popularity;
    vector<pair<int, string>> top3;

    TrieNode() {
        isWordEnd = false;
        popularity = 0;

        for (int i = 0; i < 26; i++)
            children[i] = nullptr;
    }
};

class Trie {
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    // Insert a word along with its popularity
    void insert(string word, int popularity) {
        TrieNode* curr = root;

        // Optional: maintain top3 at root as well
        updateTop3(curr->top3, word, popularity);

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                curr->children[index] = new TrieNode();

            curr = curr->children[index];

            updateTop3(curr->top3, word, popularity);
        }

        curr->isWordEnd = true;
        curr->popularity = popularity;
    }

    // Maintains top 3 most popular words
    void updateTop3(vector<pair<int, string>>& top3,
                    string word,
                    int popularity) {

        // Update popularity if word already exists
        for (auto& x : top3) {
            if (x.second == word) {
                x.first = popularity;
                sort(top3.begin(), top3.end(), greater<>());
                return;
            }
        }

        top3.push_back({popularity, word});

        sort(top3.begin(), top3.end(), greater<>());

        if (top3.size() > 3)
            top3.pop_back();
    }

    // Search complete word
    bool search(string word) {
        TrieNode* curr = root;

        for (char ch : word) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return curr->isWordEnd;
    }

    // Prefix search
    bool startsWith(string prefix) {
        TrieNode* curr = root;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return false;

            curr = curr->children[index];
        }

        return true;
    }

    // Return every word matching a prefix
    vector<string> autocomplete(string prefix) {

        TrieNode* curr = root;
        vector<string> res;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return res;

            curr = curr->children[index];
        }

        dfs(curr, res, prefix);

        return res;
    }

    // Return top 3 most popular words
    vector<string> autocompleteTop3(string prefix) {

        TrieNode* curr = root;
        vector<string> res;

        for (char ch : prefix) {
            int index = ch - 'a';

            if (curr->children[index] == nullptr)
                return res;

            curr = curr->children[index];
        }

        for (auto& x : curr->top3)
            res.push_back(x.second);

        return res;
    }

    // DFS helper
    void dfs(TrieNode* node,
             vector<string>& res,
             string word) {

        if (node->isWordEnd)
            res.push_back(word);

        for (int i = 0; i < 26; i++) {
            if (node->children[i]) {
                dfs(node->children[i],
                    res,
                    word + char('a' + i));
            }
        }
    }
};

int main() {

    Trie trie;

    trie.insert("apple", 45);
    trie.insert("app", 78);
    trie.insert("appy", 89);
    trie.insert("appygd", 94);
    trie.insert("appyqww", 96);
    trie.insert("bat", 33);

    cout << trie.search("apple") << endl;
    cout << trie.search("app") << endl;
    cout << trie.search("ap") << endl;

    cout << "\nTop 3 Suggestions:\n";

    vector<string> res = trie.autocompleteTop3("ap");

    for (auto& word : res)
        cout << word << endl;
}
```

---

## Sample Output

```
1
1
0

Top 3 Suggestions:
appyqww
appygd
appy
```

---

This is most probaly how production system may be implemented. atleast the most basic one

### Naive Approach

Store popularity only at the end node.

For every autocomplete request:

1. Traverse to the prefix node.
2. DFS the subtree.
3. Collect all matching words.
4. Sort by popularity.
5. Return the top 3.

**Complexity:** `O(M log M)`

where **M** is the number of matching words.

---

### Optimized Approach (Implemented Above)

Every node stores its own top 3 suggestions.

During insertion, every node on the word's path updates its `top3` list.

For autocomplete:

1. Traverse the prefix.
2. Return the stored top 3.

**Complexity:** `O(L)`

where **L** is the prefix length.

This is the standard design used by autocomplete systems in search engines and keyboards.
