#include<bits/stdc++.h>
using namespace std;
struct TrieNode{
    map<char,TrieNode*>child;
    bool is_last;
    string data;
    TrieNode()
    {
        for(char ch='a';ch<='z';ch++)
        {
            child[ch]=NULL;
        }
        is_last=false;
        data="not-defined";
    }
};
TrieNode *root;
void insert(string word,string meaning)
{
    TrieNode* itr=root;
    for(int i=0;i<word.size();i++)
    {
        TrieNode* nextNode=itr->child[word[i]];
        if(nextNode==NULL)
        {
            nextNode=new TrieNode();
            itr->child[word[i]]=nextNode;
        }
        itr=nextNode;
        if(i==word.size()-1)
        {
            itr->is_last=true;
            itr->data=meaning;
        }
        
    }
    
}
void insertIntoTrie(){
    root=new TrieNode();
    insert("map","a diagrammatic representation of an area");
    insert("programming","process of creating a set of instructions that tell a computer how to perform a task.");
    insert("camp","a place with temporary accommodation of huts");
    insert("camping","the activity of spending a holiday living in a tent.");
    insert("programminglanguage","computer language that is used by programmers");
}
void displayMeaning(string query)
{
    TrieNode *prevNode=root;
    int i,l=query.size();
    for(i=0;i<l;i++)
    {
        TrieNode *nextNode=prevNode->child[query[i]];
        if(nextNode==NULL)
        {
            cout<<"No results try another word"<<"\n";break;
        }
        if(i==l-1)
        {
            if(nextNode->is_last==false)
             cout<<"No results try another word"<<"\n";
            else
            {
                cout<<query<<" means "<<nextNode->data<<"\n";
            }
        }
        prevNode=nextNode;
    }
}
int main()
{
    cout<<"Enter the word whose meaning u want\n";
    string query;
    cin>>query;
    insertIntoTrie();
    displayMeaning(query);
    return 0;
}