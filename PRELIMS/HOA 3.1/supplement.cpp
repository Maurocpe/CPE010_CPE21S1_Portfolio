#include "Playlist.h"

int main() {

    Playlist playlist;

    playlist.addSong("Not You too");
    playlist.addSong("Shape of You");
    playlist.addSong("Backburner");
    playlist.addSong("Lowkey");

    playlist.playAll();

    cout << "\nNext Song\n";
    playlist.nextSong();

    cout << "\nNext Song\n";
    playlist.nextSong();

    cout << "\nPrevious Song\n";
    playlist.previousSong();

    cout << "\nRemoving Shape of You\n";
    playlist.removeSong("Shape of You");

    playlist.playAll();

    return 0;
}