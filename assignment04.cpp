// 4 Linked List Design a music playlist system using a linked list where:
// ● Songs can be added to the beginning/end
// ● Songs can be deleted
// ● Next and previous songs can be navigated

#include <bits/stdc++.h>
using namespace std;

class playlist
{
public:
    string data;
    playlist *next;
    playlist()
    {
        next = nullptr;
    }
    playlist(string song_name)
    {
        data = song_name;
        next = NULL;
    }
};
class ll
{
public:
    playlist *head;
    playlist *tail;
    playlist *currentsong;
    ll()
    {
        head = NULL;
        tail = NULL;
        currentsong = NULL;
    }

    void insert_song_end(string NameAtEnd)
    {
        playlist *newsong = new playlist(NameAtEnd);
        if (head == NULL)
        {
            head = newsong;
            tail = newsong;
            currentsong = newsong;
            return;
        }

        tail->next = newsong;
        tail = newsong;
    }
    void insert_song_beg(string NameAtBeg)
    {
        playlist *newsong = new playlist(NameAtBeg);
        if (head == NULL)
        {
            head = newsong;
            tail = newsong;
            currentsong = newsong;
            return;
        }

        newsong->next = head;
        head = newsong;
    }

    void display_songs()
    {
        if (head == NULL)
        {
            cout << "The list of song is empty!!" << endl;
            return;
        }
        else
        {
            playlist *temp = head;
            while (temp != NULL)
            {
                cout << temp->data << " -> ";
                temp = temp->next;
            }
            cout << "NULL " << endl;
        }
    }

    void deletesong(string ToDelete)
    {
        if (head == nullptr)
        {
            cout << "The list of songs is empty!!" << endl;
            return;
        }

        if (head->data == ToDelete)
        {
            playlist *toDeleteNode = head;
            head = head->next;
            if (currentsong == toDeleteNode)
                currentsong = head;
            if (head == nullptr)
                tail = nullptr;
            delete toDeleteNode;
            cout << "Song deleted successfully!" << endl;
            return;
        }

        playlist *temp = head;
        while (temp->next != nullptr && temp->next->data != ToDelete)
        {
            temp = temp->next;
        }

        if (temp->next == nullptr)
        {
            cout << "Song not found in playlist!" << endl;
            return;
        }

        playlist *toDeleteNode = temp->next;
        temp->next = toDeleteNode->next;

        if (toDeleteNode == tail)
        {
            tail = temp;
        }
        if (currentsong == toDeleteNode)
        {
            currentsong = temp;
        }

        delete toDeleteNode;
        cout << "Song deleted successfully!" << endl;
    }

    void NextSong()
    {
        if (currentsong == nullptr)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        if (currentsong->next != nullptr)
        {
            currentsong = currentsong->next;
            cout << "Now playing: " << currentsong->data << endl;
        }
        else
        {
            cout << "currently on first song" << endl;
        }
    }

    void PreviousSong()
    {
        if (currentsong == nullptr)
        {
            cout << "Playlist is empty!" << endl;
            return;
        }
        if (currentsong == head)
        {
            cout << "last song reached" << endl;
            return;
        }

        playlist *temp = head;
        while (temp->next != currentsong)
        {
            temp = temp->next;
        }
        currentsong = temp;
        cout << "Now playing: " << currentsong->data << endl;
    }
};
int main()
{
    int choice;
    ll l1;
    while (true)
    {
        string sname;
        cout << "\n=============== WELCOME TO YOUR MUSIC PLAYER ===============\n";
        cout << "1: Add song at the beginning\n";
        cout << "2: Add song at the end\n";
        cout << "3: Display playlist\n";
        cout << "4: Next song\n";
        cout << "5: Previous song\n";
        cout << "6: Delete song\n";
        cout << "7: Exit\n";
        cout << "============================================================\n";
        cout << "Enter choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice)
        {
        case 1:
            cout << "Enter the song to add at the beginning: ";
            getline(cin, sname);
            l1.insert_song_beg(sname);
            break;
        case 2:
            cout << "Enter the song to add at the end: ";
            getline(cin, sname);
            l1.insert_song_end(sname);
            break;
        case 3:
            cout << "\n============= PLAYLIST =============\n";
            l1.display_songs();
            break;
        case 4:
            l1.NextSong();
            break;
        case 5:
            l1.PreviousSong();
            break;
        case 6:
            cout << "Enter song name to delete: ";
            getline(cin, sname);
            l1.deletesong(sname);
            break;
        case 7:
            cout << "Exiting playlist. Goodbye!\n";
            return 0;
        default:
            cout << "Invalid choice! Try again.\n";
        }
    }
}
