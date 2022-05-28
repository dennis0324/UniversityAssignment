#include <stdio.h>
#include <stdlib.h>
#include "doubleListArray.h"

typedef struct songList{
    DListNode * song;
    DListNode * currentSong;
}SongList;

void print_current_music(SongList * phead){
    DListNode * p;
    for(p = phead->song->rlink; p!=phead; p = p->rlink){
        if(p == phead->currentSong){
            printf("<-|# %s #|->",p->data);
        }
        else{
            printf("<-| %s |->",p->data);
        }
    }
    printf("\n");
}

int main(){
    char ch;
    SongList * songList;
    createDList(songList->song);

    dinsert(songList->song,"Mamamia");
    dinsert(songList->song,"Dancing Queen");
    dinsert(songList->song,"Fernando");

    // songList->currentSong = songList->song->rlink;

    // do{
    //     printf("\n 명령어를 입력하세요(<,>,q): ");
    //     ch = getchar();
    //     if(ch == '>'){
    //         songList->currentSong= songList->currentSong->llink;
    //         if(songList->currentSong == songList->song){
    //             songList->currentSong = songList->currentSong->llink;
    //         }
    //         else if(ch == '>'){
    //             songList->currentSong = songList->currentSong->rlink;
    //             if(songList->currentSong == songList->song){
    //                 songList->currentSong = songList->currentSong->rlink;
    //             }
    //         }
    //         print_current_music(&songList);
    //         getchar();
    //     }
    // }while(ch != 'q');

    return 0;
}