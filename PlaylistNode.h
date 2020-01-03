#pragma once

#include <iostream>
#include <string>
//#include <vector>

using namespace std;

#ifndef PlaylistNode_H
#define PlaylistNode_H

class PlaylistNode {
public:
	PlaylistNode();
	PlaylistNode(string, string, string, int);
	PlaylistNode(string, string, string, int, PlaylistNode*);

	void InsertAfter(PlaylistNode*);

	PlaylistNode *GetNext();
	void SetNext(PlaylistNode*);

	string	GetID() const;
	void  SetID(string);

	string	GetSongName() const;
	void SetSongName(string);

	string	GetArtistName() const;
	void SetArtistName(string);

	int	GetSongLength() const;
	void SetSongLength(int);

	void PrintPlaylistNode(PlaylistNode*) const;


private:
	string uniqueID;
	string songName;
	string artistName;
	int songLength;
	PlaylistNode* nextNodePtr;


};

#endif