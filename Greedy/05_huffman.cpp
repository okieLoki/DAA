#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int freq;
    char ch;
    Node *left, *right;

    Node(int freq, char ch, Node *left = NULL, Node *right = NULL)
    {
        this->freq = freq;
        this->ch = ch;
        this->left = left;
        this->right = right;
    }
};

struct compare
{
    bool operator()(Node *l, Node *r)
    {
        return l->freq > r->freq;
    }
};

void printCodes(Node *root, string s)
{
    if (root == nullptr)
    {
        return;
    }
    if (root->ch != '$')
    {
        cout << root->ch << ":" << s << endl;
    }
    printCodes(root->left, s + '0');
    printCodes(root->right, s + '1');
}

void printHCodes(char arr[], int freq[], int n)
{
    priority_queue<Node *, vector<Node *>, compare> h;
    for (int i = 0; i < n; i++)
    {
        h.push(new Node(freq[i], arr[i]));
    }

    while (h.size() > 1)
    {
        Node *l = h.top();
        h.pop();

        Node *r = h.top();
        h.pop();

        h.push(new Node(l->freq + r->freq, '$', l, r));
    }
    printCodes(h.top(), "");
}

int main()
{
    char arr[] = {'a', 'b', 'c', 'd', 'e', 'f'};
    int freq[] = {5, 9, 12, 13, 16, 45};

    printHCodes(arr, freq, 6);
}