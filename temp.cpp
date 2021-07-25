#include<bits/stdc++.h>
using namespace std;

struct date{
    int day,month,year;
};

struct student{
    string name;
    int roll_num,standard;
    char section;
    date *dob;
};

struct TrieNode{
    map<char,TrieNode*>child;
    bool is_last;
    student *info;
    TrieNode(){
        for(char ch='a';ch<='z';ch++)
        {
            child[ch]=NULL;
        }
        is_last=false;
        info=NULL;
    }
};
TrieNode *root=NULL;

void insert(string name)
{
    int l=name.size();
    TrieNode *itr=root;
    for(int i=0;i<l;i++)
    {
        //checking if name[i] already exists or not;
        TrieNode *nextNode=itr->child[name[i]];
        if(nextNode==NULL)
        {
            nextNode=new TrieNode();
            itr->child[name[i]]=nextNode;
        }
        itr=nextNode;

        if(i==l-1)
        {
            itr->is_last=true;
            itr->info=new student;
            cout<<"\nEnter student details\n";
            cout<<"Enter roll num\n";
            cin>>itr->info->roll_num;
            cout<<"\nEnter Standard\n";
            cin>>itr->info->standard;
            cout<<"\nEnter section\n";
			cin>>itr->info->section;
            cout<<"\nEnter dob\nday: ";
			itr->info->dob = new date();
            cin>>itr->info->dob->day;
			cout<<"\nEnter month: ";
			cin>>itr->info->dob->month;
			cout<<"\nEnter year: ";
			cin>>itr->info->dob->year;
			cout<<"\n";
        }
    }
}
void insertIntoTrie(int n)
{
    root = new TrieNode();
    string name;
    for(int i=0;i<n;i++)
    {
        cout<<"enter student name\n";
        cin>>name;
        insert(name);
    }
}
void displayContactInfo(TrieNode* curNode,string prefix)
{
    if(curNode->is_last)
    {
        cout << prefix << endl; 
		cout<<curNode->info->roll_num<<endl;
		cout<<curNode->info->standard<<"-"<<curNode->info->section<<endl;
		cout<<curNode->info->dob->day<<"/"<<curNode->info->dob->month<<"/"<<curNode->info->dob->year<<"/"<<endl<<endl;
    }

    for(char ch='a';ch<='z';ch++)
    {
        TrieNode *nextNode=curNode->child[ch];
        if(nextNode!=NULL) 
        {
            displayContactInfo(nextNode,prefix+ch);
        }
    }
}
void displayContacts(string query)
{
    TrieNode *prevNode=root;
    string prefix="";
    int i;
    for(i=0;i<query.size();i++)
    {
        prefix+=query[i];
        char lastChar=query[i];

        TrieNode *curNode=prevNode->child[lastChar];
        if(curNode==NULL)
        {
            cout<<"\nNo results found for "<<prefix<<"\n";
            i++;break;
        }
        cout << "\nSuggestions based on :" << prefix 
			<< " are \n"; 
		displayContactInfo(curNode, prefix); 

        prevNode=curNode;
    }
    //if one search fails for a particular prefix we return no results for the rest
    for(;i<query.size();i++)
    {
        prefix+=query[i];
        cout << "\nNo Results Found for : " << prefix 
			<< "\n"; 
    }
}

int main()
{
    int n;
    cout<<"Enter number of students\n";
    cin>>n;
    insertIntoTrie(n);
    string query;
    cout<<"Enter Your Query(Name of student you wish to search)";
    cin>>query;

    displayContacts(query);
    return 0;
}