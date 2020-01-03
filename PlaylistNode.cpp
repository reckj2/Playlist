#include <iostream>
#include <string>
#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
	uniqueID = "none";
	songName = "none";
	artistName = "none";
	songLength = 0;
	this->nextNodePtr = 0;
}

PlaylistNode::PlaylistNode(string ID, string name, string artist, int len){
	uniqueID = ID;
	songName = name;
	songLength = len;
	artistName = artist;
}

PlaylistNode::PlaylistNode(string ID, string name, string artist, int len, PlaylistNode* _next) {
	uniqueID = ID;
	songName = name;
	songLength = len;
	artistName = artist;
	nextNodePtr = _next;
}

void PlaylistNode::InsertAfter(PlaylistNode* n) {
	PlaylistNode *temp1 = new PlaylistNode();
	PlaylistNode *temp2 = new PlaylistNode();
	//temp1 = 0;
	//*temp1 = nextNodePtr;
	/*temp1 = this->nextNodePtr;
	this->nextNodePtr = n;
	n->nextNodePtr = temp1;*/
	temp2 = this;
	temp1 = n;
	if (temp2->nextNodePtr == 0) {
		nextNodePtr = temp1;
	}
	else {
		while (temp2->nextNodePtr != 0) {
			temp2 = temp2->nextNodePtr;
		}
		temp2->nextNodePtr = temp1;
	}


	//temp1->nextNodePtr = nextNodePtr;
	////temp1 = temp1->nextNodePtr;
	//
	//if (temp1->GetID() == "none") {
	//	nextNodePtr = n;
	//	return;
	//}
	//while (temp1->nextNodePtr != NULL) {
	//	temp1 = temp1->nextNodePtr;
	//}
	//n->nextNodePtr = temp1->nextNodePtr;
	//temp1->nextNodePtr = n;
	//return;

	
}

PlaylistNode* PlaylistNode::GetNext(){
	return nextNodePtr;
}

void PlaylistNode::SetNext(PlaylistNode* n) {
	nextNodePtr = n;
}

void PlaylistNode::SetID(string ID) {
	uniqueID = ID;
}
void PlaylistNode::SetSongName(string Name) {
	songName = Name;
}
void PlaylistNode::SetArtistName(string Artist) {
	artistName = Artist;
}
void PlaylistNode::SetSongLength(int length) {
	songLength = length;
}

string PlaylistNode::GetID() const {
	return uniqueID;
}

string PlaylistNode::GetSongName() const {
	return songName;
}

string PlaylistNode::GetArtistName() const {
	return artistName;
}

int PlaylistNode::GetSongLength() const {
	return songLength;
}

void PlaylistNode::PrintPlaylistNode(PlaylistNode *head) const {
	PlaylistNode* temp = NULL;
	temp = new PlaylistNode();
	PlaylistNode* temp2 = NULL;
	temp2 = new PlaylistNode();
int i = 1;

	if (head->GetNext() == 0) {
		cout << "Playlist is empty" << endl;
		cout << endl;
	}
	else {
		temp = head;
		temp2 = temp;
		temp = temp->GetNext();
		while (temp2->GetNext() != 0) {
			cout << i << "." << endl;
			cout << "Unique ID: " << temp->GetID() << endl;
			cout << "Song Name: " << temp->GetSongName() << endl;
			cout << "Artist Name: " << temp->GetArtistName() << endl;
			cout << "Song Length (in seconds): " << temp->GetSongLength() << endl;
			temp2 = temp;
			temp = temp->GetNext();
			i++;
			cout << endl;
		}
	}
}




\

