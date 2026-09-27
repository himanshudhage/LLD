//aggregation

#include<iostream>
#include<vector>
#include<string>

using namespace std;
class Artist{

    private:
    string name;
    
    public:
    Artist(string name){
        this->name = name;
    }

    string get_name(){
        return name;
    }
};

class Song{
    private:

    string title;
    Artist*artist;
    int duration;

    public:

    Song(string title,Artist*artist,int duration){
        this->title = title;
        this->artist =artist;
        this->duration = duration;
    }

    string get_title(){
        return title;
    }

    Artist* get_artist(){
        return artist;
    }

    int get_duration(){
        return duration;
    }

    string toString(){
        return title + " by " + artist->get_name() + " (" + to_string(duration) + "s)";
    }

};

class Playlist{
    private:

    string name;
    vector<Song*>songs;

    public:

    Playlist(string name){
        this->name = name;
    }

    void add_song(Song*song){
        songs.push_back(song);
    }

    void remove_song(Song*song){
        for(int i = 0 ; i < songs.size();i++){
            if(songs[i] == song){
                songs.erase(songs.begin() + i);
                break;
            }
        }
    }

    int get_song_count(){
        return songs.size();
    }

    int get_total_duration(){
        int ttl_dur = 0;

        for(int i = 0 ; i < songs.size();i++){
            ttl_dur += songs[i]->get_duration();
        }

        return ttl_dur;
    }

    string get_name(){
        return name;
    }

    vector<Song*> get_songs(){
        return songs;
    }
};

class User{
    private:
    string name;
    vector<Playlist*>playlists;

    public:

    User(string name){
        this->name = name;
    }

    Playlist*create_playlist(string playlist_name){
        Playlist*p = new Playlist(playlist_name);
        playlists.push_back(p);

        return p;
    }

    void delete_playlist(Playlist* playlist){
        for(int i = 0 ; i < playlists.size();i++){
            if(playlists[i] == playlist){
                playlists.erase(playlists.begin() + i);
                break;
            }
        }
        delete playlist;
    }

    string get_name(){
         return name;
    }

     vector<Playlist*> get_playlists() {
        return playlists;
    }
};

class Library {
private:
    vector<Song*> songs;

public:
    void add_song(Song* song) {
        songs.push_back(song);
    }

    int get_song_count() {
        return songs.size();
    }

    vector<Song*> get_songs() {
        return songs;
    }
};

int main() {

    // Create artists
    Artist coldplay("Coldplay");
    Artist adele("Adele");

    // Create songs
    Song yellow("Yellow", &coldplay, 269);
    Song clocks("Clocks", &coldplay, 307);
    Song hello("Hello", &adele, 295);
    Song someone("Someone Like You", &adele, 285);

    // Create library and add songs
    Library library;
    library.add_song(&yellow);
    library.add_song(&clocks);
    library.add_song(&hello);
    library.add_song(&someone);

    // Create user
    User alice("Alice");

    // Create playlists
    Playlist* workout = alice.create_playlist("Workout Mix");
    Playlist* chill = alice.create_playlist("Chill Vibes");

    // Add songs to Workout playlist
    workout->add_song(&yellow);
    workout->add_song(&clocks);
    workout->add_song(&hello);

    // Add songs to Chill playlist
    chill->add_song(&hello);
    chill->add_song(&someone);

    // Display library
    cout << "Library has " << library.get_song_count() << " songs\n\n";

    // Display Workout playlist
    cout << workout->get_name() << endl;
    cout << "Songs: " << workout->get_song_count() << endl;
    cout << "Total Duration: " << workout->get_total_duration() << " seconds\n";

    vector<Song*> workoutSongs = workout->get_songs();

    for (int i = 0; i < workoutSongs.size(); i++) {
        cout << workoutSongs[i]->toString() << endl;
    }

    cout << endl;

    // Display Chill playlist
    cout << chill->get_name() << endl;
    cout << "Songs: " << chill->get_song_count() << endl;
    cout << "Total Duration: " << chill->get_total_duration() << " seconds\n";

    vector<Song*> chillSongs = chill->get_songs();

    for (int i = 0; i < chillSongs.size(); i++) {
        cout << chillSongs[i]->toString() << endl;
    }

    cout << endl;

    // Delete Workout playlist
    string playlistName = workout->get_name();
    alice.delete_playlist(workout);

    cout << "Playlist '" << playlistName << "' deleted.\n\n";

    // Verify other objects still exist
    cout << "Library still has " << library.get_song_count() << " songs." << endl;
    cout << "Playlist '" << chill->get_name() << "' still has "
         << chill->get_song_count() << " songs." << endl;
    cout << "Song still exists: " << yellow.get_title() << endl;

    return 0;
}