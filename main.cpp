/*
* File: main.cpp
* Author: Joshua Reck
* NetID: reckj2
*
* Description: Creates a playlist using linked lists and header files.
*
*/

#include <iostream>
#include <string>

#include "PlaylistNode.h"

using namespace std;

int main(void) {
	//Creates variables for user input
	char userOption = 'z';
	string userTitle;

	//Creates linked list nodes of class PlaylistNode
	PlaylistNode* head = NULL;
	head = new PlaylistNode();
	PlaylistNode* temp = NULL;
	temp = new PlaylistNode();
	PlaylistNode* temp2 = NULL;
	temp2 = new PlaylistNode();
	PlaylistNode* temp3 = NULL;
	temp3 = new PlaylistNode();
	PlaylistNode* temp4 = NULL;
	temp4 = new PlaylistNode();
	PlaylistNode* temp5 = NULL;
	temp5 = new PlaylistNode();
	PlaylistNode* n = NULL;

	//creates variables for user input
	string tempID;
	string tempName;
	string tempArtist;
	int tempLength;
	int tempnum, tempnum2;
	int i, j;
	int num;
	int totalTime;

	//prompts user for playlist title
	cout << "Enter playlist's title:" << endl;
	getline(cin, userTitle);
	cout << endl;
	
	//while the user does not choose the quit option
	while (userOption != 'q') {
		
		//Displays menu for user
		cout << userTitle << " PLAYLIST MENU" << endl;
		cout << "a - Add song" << endl;
		cout << "d - Remove song" << endl;
		cout << "c - Change position of song" << endl;
		cout << "s - Output songs by specific artist" << endl;
		cout << "t - Output total time of playlist (in seconds)" << endl;
		cout << "o - Output full playlist" << endl;
		cout << "q - Quit" << endl;
		cout << endl;
		
		//recieve user input
		cout << "Choose an option:" << endl;
		cin >> userOption;

		// while the user has not chosen a valid option
		while (userOption != 'a' && userOption != 'd' && userOption != 'c' && userOption != 's' && userOption != 'o' && userOption != 't' && userOption != 'q') {
			cout << "Choose an option:";
			cin >> userOption;
			cout << endl;
		}
		
		//if the user chooses to add a song
		if (userOption == 'a') {
			cout <<"ADD SONG" << endl;
			n = new PlaylistNode();

			cin.ignore(256, '\n');

			//Recieves user input for song attributes
			cout << "Enter song's unique ID:" << endl;
			getline(cin, tempID);
			cout << "Enter song's name:" << endl;
			getline(cin, tempName);
			cout << "Enter artist's name:" << endl;
			getline(cin, tempArtist);
			cout << "Enter song's length (in seconds):" << endl;
			cin >> tempLength;

			//sets song attributes
			n->SetID(tempID);
			n->SetSongName(tempName);
			n->SetArtistName(tempArtist);
			n->SetSongLength(tempLength);

			//adds new node to linked list
			head->InsertAfter(n);
			cout << endl;
		}
		
		//if user chooses to remove a song
		if (userOption == 'd') {
			
			//receives user input
			cin.ignore(256, '\n');
			cout << "REMOVE SONG" << endl;
			cout << "Enter song's unique ID:" << endl;
			getline(cin, tempID);
			num = 0;
			
			//temporary nodes set for traversing
			temp = head;
			temp2 = temp;
			temp = temp->GetNext();
			
			//While song's ID is not the same as user input
			while (tempID.compare(temp->GetID()) != 0) {
				//If 
				if (temp->GetNext() == 0) {
					break;
				}
				temp2 = temp;
				temp = temp->GetNext();
			}
			
			
			if (tempID.compare(temp->GetID()) == 0) {
				num = 1;
				cout << "\"" << temp->GetSongName() << "\" removed." << endl;
				temp2->SetNext(temp->GetNext());
				cout << endl;
			}
			if (num == 0) {
				cout << "Song not found, nothing removed" << endl;
			}
			

	
		}
		if (userOption == 'c') {
			cin.ignore(256, '\n');
			cout << "CHANGE POSITION OF SONG" << endl;
			cout << "Enter song's current position:" << endl;
			cin >> tempnum;
			cout << "Enter new position for song:" << endl;
			cin >> tempnum2;
			if (tempnum < tempnum2) {
				temp = head;
				temp = temp->GetNext();
				temp2 = head;
				temp3 = head;
				temp3 = temp3->GetNext();
				temp4 = head;
				temp5 = head;

				for (i = 1; i < tempnum; i++) {
					temp2 = temp;
					temp = temp->GetNext();
				}
				for (j = 1; j < tempnum2; j++) {
					temp4 = temp3;
					temp3 = temp3->GetNext();
				}
			
					temp2->SetNext(temp->GetNext());
					temp->SetNext(temp3->GetNext());
					temp3->SetNext(temp);
			}
			else {
				temp = head;
				temp = temp->GetNext();
				temp2 = head;
				temp3 = head;
				//temp3 = temp3->GetNext();
				temp4 = head;
				temp5 = head;

				for (i = 1; i < tempnum; i++) {
					temp2 = temp;
					temp = temp->GetNext();
				}
				for (j = 1; j < tempnum2; j++) {
					temp4 = temp3;
					temp3 = temp3->GetNext();
				}

				temp2->SetNext(temp->GetNext());
				temp->SetNext(temp3->GetNext());
				temp3->SetNext(temp);
			}

			cout << "\"" << temp->GetSongName() << "\"" << " moved to position " << tempnum2 << endl;
			cout << endl;


		}
		if (userOption == 's') {
			cin.ignore(256, '\n');
			cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
			cout << "Enter artist's name:" << endl;
			getline(cin, tempArtist);
			cout << endl;
			temp = head;
			temp2 = temp;
			temp = temp->GetNext();
			i = 1;
			while (temp2->GetNext() != 0) {
				if (tempArtist.compare(temp->GetArtistName()) == 0) {
					cout << i << "." << endl;
					cout << "Unique ID: " << temp->GetID() << endl;
					cout << "Song Name: " << temp->GetSongName() << endl;
					cout << "Artist Name: " << temp->GetArtistName() << endl;
					cout << "Song Length (in seconds): " << temp->GetSongLength() << endl;
					cout << endl;
				}
				temp2 = temp;
				temp = temp->GetNext();
				i++;

			}

		}
		if (userOption == 't') {
			cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
			totalTime = 0;
			temp = head;
			temp2 = temp;
			temp = temp->GetNext();
			while (temp2->GetNext() != 0) {
				totalTime = totalTime + temp->GetSongLength();
				temp2 = temp;
				temp = temp->GetNext();
			}
			cout << "Total time: " << totalTime << " seconds" << endl;
			cout << endl;


		}
		if (userOption == 'o') {
			cout << userTitle << " - OUTPUT FULL PLAYLIST" << endl;
			temp->PrintPlaylistNode(head);
		}


	}







	return 0;
}
