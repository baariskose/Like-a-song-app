#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int a;
FILE *dosya;
char calanSarki[20] = "";
int elemanSayisi = 0;
struct n {
    char songName[30];
    struct n* next;
};
typedef struct n node;
node * root = NULL ;

void bastir(node *r) { // default olarak iteri bir ilerlet
    if(r != NULL) {
    node * iter= r;
    printf("%s\n",iter->songName);
    iter = iter-> next;
    while(iter != r) {
    printf("%s\n" , iter->songName);
    iter = iter ->next;
    }
}
 printf("*****\n");
}
void tersBastir(node *r) {
 if(r != NULL) {
        node *current,*prev,*next,*last;

    last = r;
    prev = r;
    current = r-> next;
    r = r->next;
    while(r !=last ) {
        r = r->next;
        current->next = prev;
        prev = current;
        current = r;
    }
    current-> next = prev;
    r= prev;
    bastir(r);
    }
    else {
        printf("Liste Boş");
    }

}
void sonaEkle(node *r , char songName[]) { // sona eleman ekle ve tekrar
    if(r == NULL ){ // boþsa
        r = (node*) malloc(sizeof(node));
        r->next = r;
        strcpy(r-> songName,songName);

         root = r;
    }                        // dögü kur
    node *iter = r;
    while(iter-> next != r) {
        iter= iter->next;
    }
    iter-> next = (node*)malloc(sizeof(node));
    strcpy( iter->next-> songName,songName);

    iter-> next -> next = r;
}
node* basaEkle(node *r , char songName[]) {
     if(r == NULL ){ // boþsa
        r = (node*) malloc(sizeof(node));
        r->next = r;
        strcpy(r-> songName,songName);
        return r;
    }
    node * temp = (node*)malloc(sizeof(node));
            strcpy(temp-> songName , songName);
            temp -> next = r;
            node* iter = r;
            while(iter->next != r) {
                iter = iter -> next;
            }
            iter  ->  next = temp;
            r = temp;
            return r;
}
node* moveSongAfter(node* r, char songName[] ,char referenceSongName[] ) {

        if(r!= NULL) {
             node*iteratorSonBulucu = r;

            if(!strcmp(r->songName,songName)) {
                    node * iter = r;
                    node *tasinacakNode=(node*)malloc(sizeof(node));
                    tasinacakNode  = r;
                    while(iter->next != r) {
                        iter = iter-> next;
                    }
                    r = r->next;
                   iter-> next = r;

                   node *iter2 = r;
                    while(iter2->next != r && strcmp(iter2->songName,referenceSongName)) {
                        iter2 = iter2 -> next;
                    }
                    tasinacakNode ->next = iter2->next;
                    iter2-> next = tasinacakNode;
                    return r;
            }

            else {
                node * iter2 = r;
            node *tasinacakNode=(node*)malloc(sizeof(node));
            while(iter2 -> next !=r && strcmp(iter2-> next->songName,songName)) {
                iter2 = iter2 -> next;
            }
            tasinacakNode = iter2->next;
            iter2-> next = iter2->next ->next;
            node * iter = r;
            while(iter-> next != r && strcmp(iter->songName,referenceSongName) ) {
            iter = iter -> next;
            }
            tasinacakNode ->next = iter->next;
            iter->next = tasinacakNode;
            strcpy(tasinacakNode -> songName,songName) ;
            return r;
            }

        }
}
node* moveSongBefore(node* r, char songName[] ,char referenceSongName[]) {
    if(r!= NULL) {
            if(!strcmp(r->songName,songName)) {
                    node * iter = r;
                    node *tasinacakNode=(node*)malloc(sizeof(node));
                    tasinacakNode  = r;
                    while(iter->next != r) {
                        iter = iter-> next;
                    }
                    r = r->next;
                   iter-> next = r;

                   node *iter2 = r;
                    while(iter2->next != r && strcmp(iter2->next->songName,referenceSongName)) {
                        iter2 = iter2 -> next;
                    }
                    tasinacakNode ->next = iter2->next;
                    iter2-> next = tasinacakNode;
                    return r;
            }
            else if(!strcmp(r->songName,referenceSongName)) {
                    node * iter = r;
                    node * iterSon = r;
                    node *tasinacakNode=(node*)malloc(sizeof(node));
                    while(iter->next != r && strcmp(iter->next ->songName,songName)){
                        iter = iter->next;
                    }
                    tasinacakNode = iter->next;
                    iter->next = iter->next ->next;
                    while(iterSon->next != r) {
                        iterSon= iterSon-> next;
                    }
                    tasinacakNode ->next = r;
                     iterSon->next = tasinacakNode;
                        r= tasinacakNode;
                    return r;
            }
            else {
                node * iter2 = r;
            node *tasinacakNode=(node*)malloc(sizeof(node));
            while(iter2 -> next !=r && strcmp(iter2-> next->songName,songName)) {
                iter2 = iter2 -> next;
            }
            tasinacakNode = iter2->next;
            iter2-> next = iter2->next ->next;
            node * iter = r;
            while(iter-> next != r && strcmp(iter->next->songName,referenceSongName) ) {
            iter = iter -> next;
            }
            tasinacakNode ->next = iter->next;
            iter->next = tasinacakNode;
            strcpy(tasinacakNode -> songName,songName) ;
            return r;
            }

        }
}
void sonrakiSarki(node* r) {
        if(r!=NULL) {
            if(!strcmp(calanSarki,"")) {
                node * iter = r;
                strcpy(calanSarki,r->songName);
                printf("Playing %s\n*****\n",calanSarki);
            }
            else{
                node * iterCalanSarki = r;
                while(iterCalanSarki->next != r && strcmp(iterCalanSarki->songName,calanSarki) ) {
                        iterCalanSarki = iterCalanSarki->next;
                }

                    strcpy(calanSarki,iterCalanSarki->next->songName);
                     printf("Playing %s\n*****\n",calanSarki);
            }
        }
}
void oncekiSarki(node * r) {
    if(r != NULL) {
        if(!strcmp(calanSarki,"")) {
            node * iter = r;
                while(iter->next != r){
                    iter = iter->next;
                }
                strcpy(calanSarki,iter->songName);
                printf("Playing %s\n*****\n",calanSarki);
        }
        else{
                node * iterCalanSarki = r;
                while(iterCalanSarki->next != r && strcmp(iterCalanSarki->next->songName,calanSarki) ) {
                        iterCalanSarki = iterCalanSarki->next;
                }

                    strcpy(calanSarki,iterCalanSarki->songName);
                    printf("Playing %s\n*****\n",calanSarki);
        }
    }
}
node* Reverse(node *r) {
    if(r != NULL) {
        node *current,*prev,*next,*last;

    last = r;
    prev = r;
    current = r-> next;
    r = r->next;
    while(r !=last ) {
        r = r->next;
        current->next = prev;
        prev = current;
        current = r;
    }
    current-> next = prev;
    r= prev;
    return r;
    }
}
node *Delete(node *r, char songName[]) {
    if(r!=NULL){
        node *temp;
        node *iter = r;
    if(!strcmp(r -> songName,songName)) {
            // rootu silersek ilk eleman yani
            if(strcmp(r->songName,calanSarki)) {
                 while(iter -> next != r) {
            iter = iter -> next;
        }
        iter->next = r->next;
        free(r);
        elemanSayisi--;
        return iter->next;
            }else {
                printf("Cannot remove the playing song\n*****\n");
            }
    }
        while(iter -> next != r && strcmp(iter->next-> songName,songName) )  { // silmek istediðimiz yere
        iter = iter -> next;                           // kadar gelirse
        }
        if(strcmp(iter->next,calanSarki)) {
            if(iter -> next == r) {
            return r;
        }
        temp = iter -> next;
        iter -> next = iter -> next -> next;
        free(temp);
        elemanSayisi--;
        return r;
        }
        else {
            printf("Cannot remove the playing song\n*****\n");
        }
    }
}
void Oku() {
 if((dosya =fopen("input.txt","r+"))!= NULL) {
    while(!feof(dosya)) {
            char * str;
            char arr[100];
        str = fgets(arr,100,dosya);
        char *ilkKisimReverse = strtok(str,"\n");
        if(!strcmp(ilkKisimReverse,"ReversePlaylist")) {
                if(root != NULL) {
                root =Reverse(root);
                //bastir(root);
                //printf("revers girdi\n");
                }


        }
        else {
            char *ilkKisim  = strtok(str,"\t");
            if(!strcmp(ilkKisim,"PlaySong")) {



                    char *playKisim = malloc(50);
                    playKisim = strtok(NULL,"\n");
                    if(root != NULL && elemanSayisi>0) {
                       if(!strcmp(playKisim,"N")) {
                        sonrakiSarki(root);
                    }
                    else {
                        oncekiSarki(root);
                    }
                    }
                    else {
                        printf("No songs to play\n*****\n");
                    }
                    //printf("%s: %s\n",ilkKisim,playKisim);
            }
            else if(!strcmp(ilkKisim,"PrintPlaylist")) {
                    char *playKisim = malloc(50);
                    playKisim = strtok(NULL,"\n");
                    if(root!=NULL && elemanSayisi>0) {
                         if(!strcmp(playKisim,"F")) {
                        bastir(root);
                    }
                    else if(!strcmp(playKisim,"R")) {
                            if(root != NULL) {
                                 root = Reverse(root);
                                bastir(root);
                                root = Reverse(root);
                            }

                    }
                    }
                    else {
                        printf("No songs to print\n*****\n");

                    }

                    //printf("%s: %s\n",ilkKisim,playKisim);
            }
            else if(!strcmp(ilkKisim,"InsertSong")) {
                    char *yon = malloc(50);
                    yon = strtok(NULL,"\t");
                    char *songName = malloc(50);
                    songName = strtok(NULL,"\n");
                    if(!strcmp(yon,"H")) {
                        root = basaEkle(root,songName);
                        elemanSayisi++;
                        //bastir(root);
                    }
                    else if(!strcmp(yon,"T")) {
                        sonaEkle(root,songName);
                        elemanSayisi++;
                         //bastir(root);
                    }
                    //printf("%s: %s %s\n",ilkKisim,yon,songName);
            }
            else if(!strcmp(ilkKisim,"MoveSong")) {
                    char *yon = malloc(50);
                    yon = strtok(NULL,"\t");
                    char *changesongName = malloc(50);
                    changesongName = strtok(NULL,"\t");
                    char *referanssongName = malloc(50);
                    referanssongName = strtok(NULL,"\n");
                    if(!strcmp(yon,"A") ) {
                        root = moveSongAfter(root,changesongName,referanssongName);
                    }
                    else if(!strcmp(yon,"B")) {
                        root = moveSongBefore(root,changesongName,referanssongName);
                        //bastir(root);
                    }
                    //printf("%s: %s %s %s\n",ilkKisim,yon,changesongName,referanssongName);
            }
            else if(!strcmp(ilkKisim,"RemoveSong")) {
                    if(root != NULL && elemanSayisi >0) {
                    char *deletesongName = malloc(50);
                    deletesongName = strtok(NULL,"\n");
                    root = Delete(root,deletesongName);
                    }
            }
        }
    }
    }

}
int main()
{
    a= 0;
   // satirHesapla();
   // printf("%d asdsa",a);

    Oku();

    return 0;
}
