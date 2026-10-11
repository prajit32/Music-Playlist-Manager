#include<iostream>
using namespace std;

class song{
	public:
		song *prev;             // Points to the previous song.
		song *next;             // Points to the next song.
		string title;
		string artist;
		
		song(string x,string y)
		{
			prev=NULL;
			next=NULL;
			title=x;                     
			artist=y;
		}
};

class playlist{
	private:
		song *head;           // Points to the first song.
	public:
		song *current;       // Points to the currently selected song.
		
		playlist()
		{
		head=NULL;
		current=NULL;
		}
		
		int empty()                //empty function
		{
			if(head==NULL)
			{
				return 1;
			}
			else
			{
				return 0;
			}
		}
		
		void insert(string x,string y)           //insert function
		{
			song *p=new song(x,y);            // p points to the newly created node.
			if(empty())
			{
				head=p;
				current=head;
			}
			else
			{
				song *q=head;                // q is used to traverse the playlist.
		    	while(q->next!=NULL)
		    	{
		    		q=q->next;
				}
				q->next=p;
				p->prev=q;
			}
			cout<<"Song Added Successfully!!"<<endl;
		}
		
		void remove(string x)                    //delete function
		{
    if(empty())
    {
        cout<<"Playlist is Empty"<<endl;
        return;
    }

    song *q=head;                // q searches the list and p points to the node to be deleted.
    song *p=NULL;                            

    if(q->title==x)             //delete head song
    {
        p=head;
        head=head->next;

        if(current==p)
        current=head;

        if(head!=NULL)
        head->prev=NULL;

        delete p;
        return;
    }

    while(q->next!=NULL)
    {
        if(q->next->title==x)              //(93-96) middle song delete
        {
            p=q->next;
            q->next=p->next;

            if(p->next!=NULL)              //(98-99) last song delete
            p->next->prev=q;

            if(current==p)
                current=q;

            delete p;
            return;
        }

        q=q->next;
    }

    cout<<"Song '"<<x<<"' Not Found in playlist"<<endl;               //if song not found
}
	   	void play(string x)                                      //song play function
	   	{
	   		if(current==NULL)                                   //
	   		{
                cout << "Playlist is empty" << endl;
                return;
			}
	   		else
	   		{
			   if(x=="next")                                   //play next song
	   		    {
	   			if(current->next==NULL)	
	   			{
	   				cout<<"Last Song (Can not play next)"<<endl;
				}
				else
				{
					current=current->next;
				}
			}
			
			else if(x=="previous")
			{
				if(current->prev==NULL)
				{
					cout<<"First Song (Can not play previous)"<<endl;
				}
				else
				{
					current=current->prev;
				}
			}
			cout<<"Current Song playing:"<<current->title<<endl;        //current song playing/showing..(x==current)..directly
			}
		}

		void playCompletePlaylist()                                	// Play Complete Playlist
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			song *q=head;

			while(q!=NULL)
			{
				current=q;
				cout<<"Current Song playing:"<<current->title<<endl;
				q=q->next;
			}
		}

		void repeatAll(int repetitions)              // Repeat All
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
				return;
			}

			for(int i=1;i<=repetitions;i++)
			{
				cout<<"Repetition "<<i<<":"<<endl;

				song *q=head;

				while(q!=NULL)
				{
					current=q;
					cout<<"Current Song playing:"<<current->title<<endl;
					q=q->next;
				}
			}
		}
		
		void displayforward()
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
			}
			else
			{
			song *q=head;
			cout<<"Forward Display: "<<endl;
			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
			    q=q->next;
			}
	    	}
     	}
		 
		void displaybackward()
		{
			if(empty())
			{
				cout<<"Playlist is Empty"<<endl;
			}
			else
			{
			song *q=head;
			cout<<"Backward Display:"<<endl;
			while(q->next!=NULL)
			{
				q=q->next;
			}
			while(q!=NULL)
			{
				cout<<q->title<<"<=>";
				q=q->prev;
			}
	     	}
		}
};

int main()
{
    playlist p;
    int choice;
    string title, artist;

    do
    {
        cout << "**** MUSIC PLAYLIST ****" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Display Playlist in Forward" << endl;
        cout << "4. Display Playlist in Reverse" << endl;
        cout << "5. Play Current Song" << endl;
        cout << "6. Play Next Song" << endl;
        cout << "7. Play Previous Song" << endl;
        cout << "8. Play Complete Playlist" << endl;
        cout << "9. Repeat All" << endl;
        cout << "10. Show Current Song" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter your choice: ";
        cin >> choice;cout<<endl;
        
        switch(choice)
        {
            case 1:
                cout << "Enter song title: ";cin>>title;             //add song
                cout << "Enter artist name: ";cin>>artist;
                p.insert(title,artist);break;
                
            case 2:
                cout << "Enter song title to delete: ";             //delete song
                cin >> title;
                p.remove(title);break;
                
            case 3:
                p.displayforward();break; cout<<endl;            //display forward
                
            case 4:
                p.displaybackward();break;                      //display backward
                
            case 5:
                p.play("current");break;                         // Play current song
                
            case 6:
                p.play("next");break;                           // Play next song
                
            case 7:
                p.play("previous");break;                       // Play previous song

            case 8:
                p.playCompletePlaylist();break;                 // Play complete playlist

            case 9:                                             // Repeat all
                {
                    int repetitions;
                    cout<<"Enter number of repetitions: ";
                    cin>>repetitions;
                    p.repeatAll(repetitions);
                }
                break;

            case 10:
                p.play("current");break;                         // Show current song
            
            case 11:
                cout<<"Exiting..." <<endl;break;             //exiting from menu
                
            default:
                cout<<"Invalid choice!"<<endl;
        }
        cout<<endl;
    } while(choice != 11);cout<<endl;
    return 0;
}
