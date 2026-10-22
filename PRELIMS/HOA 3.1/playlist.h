#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
#include <string>
using namespace std;

class Node {
public:
    string song;
    Node* next;
    Node* prev;

    Node(string title) {
        song = title;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist {
private:
    Node* head;
    Node* current;

public:
    Playlist() {
        head = nullptr;
        current = nullptr;
    }

    // Add a song
    void addSong(string title) {
        Node* newNode = new Node(title);
        if (head == nullptr) {
            head = newNode;
            head->next = head;
            head->prev = head;
            current = head;
        }
        else {
            Node* tail = head->prev;

            tail->next = newNode;
            newNode->prev = tail;
            newNode->next = head;
            head->prev = newNode;
        }
        cout << "\"" << title << "\" added to playlist.\n";
    }

    // Remove a song
    void removeSong(string title) {

        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;

        do {
            if (temp->song == title) {
                if (temp->next == temp) {
                    head = nullptr;
                    current = nullptr;
                }
                else {
                    temp->prev->next = temp->next;
                    temp->next->prev = temp->prev;
                    if (temp == head)
                        head = temp->next;
                    if (temp == current)
                        current = temp->next;
                }
                delete temp;
                cout << "\"" << title << "\" removed.\n";
                return;
            }
            temp = temp->next;
        } while (temp != head);
        cout << "Song not found.\n";
    }

    // It will display playlist
    void playAll() {

        if (head == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }

        Node* temp = head;
        cout << "\nPlaylist:\n";
        do {
            cout << temp->song << endl;
            temp = temp->next;
        } while (temp != head);
    }

    // Next song
    void nextSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        current = current->next;
        cout << "Now Playing: " << current->song << endl;
    }

    // Previous song
    void previousSong() {
        if (current == nullptr) {
            cout << "Playlist is empty.\n";
            return;
        }
        current = current->prev;
        cout << "Now Playing: " << current->song << endl;
    }
};

#endif