#include <map>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <math.h>
#include <sstream>
#include <chrono>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <iomanip>
#include<stdio.h>
#include<stdlib.h>

using namespace std ;

class menu {
    public :
void welcome()
{
    string msg= "Bienvenu au jeu taquin !";
    int console_width = 80;  // Width of console.
    int len = msg.length();  // Length of the string.

    if(len%2==0)
        msg+=" ";

    cout<<setw((console_width/2)+len/2)<<right<<msg<<endl;
    cout <<""<<endl;
    cout << ""<<endl;
}

void facile()
{
    int console_width = 80;
    int x=23;
    string line(23,'*');
    string secondline(23,' ');
    string thirdline="*        facile       *";
    string fourthline(23,' ');
    string sixthline(23,'*');
    secondline[0]='*';
    secondline[22]='*';
    fourthline[0]='*';
    fourthline[22]='*';
    cout<<setw((console_width/2)+x/2)<<right<<line<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< secondline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< thirdline<<endl;
    cout<<setw((console_width/2)+x/2)<<right << fourthline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< sixthline<<endl;
}

void moyen()
{
    int console_width = 80;
    int x=23;
    string line(23,'*');
    string secondline(23,' ');
    string thirdline="*        moyen        *";
    string fourthline(23,' ');
    string sixthline(23,'*');
    secondline[0]='*';
    secondline[22]='*';
    fourthline[0]='*';
    fourthline[22]='*';
    cout<<setw((console_width/2)+x/2)<<right<<line<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< secondline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< thirdline<<endl;
    cout<<setw((console_width/2)+x/2)<<right << fourthline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< sixthline<<endl;
}

void difficile()
{
    int console_width = 80;
    int x=23;
    string line(23,'*');
    string secondline(23,' ');
    string thirdline="*      difficile      *";
    string fourthline(23,' ');
    string sixthline(23,'*');
    secondline[0]='*';
    secondline[22]='*';
    fourthline[0]='*';
    fourthline[22]='*';
    cout<<setw((console_width/2)+x/2)<<right<<line<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< secondline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< thirdline<<endl;
    cout<<setw((console_width/2)+x/2)<<right << fourthline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< sixthline<<endl;
}

void ajout()
{
    int console_width = 80;
    int x=23;
    string line(23,'*');
    string secondline(23,' ');
    string thirdline="*     saisir joueur   *";
    string fourthline(23,' ');
    string sixthline(23,'*');
    secondline[0]='*';
    secondline[22]='*';
    fourthline[0]='*';
    fourthline[22]='*';
    cout<<setw((console_width/2)+x/2)<<right<<line<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< secondline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< thirdline<<endl;
    cout<<setw((console_width/2)+x/2)<<right << fourthline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< sixthline<<endl;
}


void prop()
{
    int console_width = 80;
    int x=17;
    string line(17,'*');
    string secondline(17,' ');
    string thirdline="*    concept    *";
    string fourthline(17,' ');
    string sixthline(17,'*');
    secondline[0]='*';
    secondline[16]='*';
    fourthline[0]='*';
    fourthline[16]='*';
    cout<<setw((console_width/2)+x/2)<<right<<line<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< secondline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< thirdline<<endl;
    cout<<setw((console_width/2)+x/2)<<right << fourthline<<endl;
    cout <<setw((console_width/2)+x/2)<<right<< sixthline<<endl;
}

void choix()
{
    cout<<""<<endl;
    cout<<"    * si vous voulez savoir le concept du jeu tapez 0"<<endl;
    cout<<""<<endl;

    cout<<"    * si vous voulez saisir joueur tapez 4"<<endl  ;
    cout<<""<<endl;
}
void choix2()
{
    cout<<""<<endl;
   // cout<<"    * si vous voulez savoir le concept du jeu tapez 0"<<endl;
   // cout<<""<<endl;

    cout<<"    * si vous voulez choisir le niveau facile tapez 3"<<endl;
    cout<<""<<endl;
    cout<<"    * si vous voulez choisir le niveau moyen tapez 4"<<endl;
    cout<<""<<endl;
    cout<<"    * si vous voulez choisir le niveau difficile tapez 5"<<endl;
    cout<<""<<endl ;

}
};

class Matrice {
private:
    int ** mat      ;
    int    taille   ;
    int indice_line ;
    bool quitter_while=false ;
    vector<int> historique ;
    vector< vector<int> > etats ;

public:
    //LES FFONCTIONS SET ET GET POUR LA VARIABLE QUITTER_WHILE
    void set_quitter_while(bool test ){quitter_while=test;}
    bool get_quitter_while(){return quitter_while;}

    // LES FONCTIONS SET ET GET POUR LA VARIABLE TAILLE
    void set_taille(int n){ taille = n ; }
    int get_taille(){ return taille ; }

    // LES FONCTIONS SET ET GET POUR LA VARIABLE MAT
    void set_matrice(string line){
        vector<int> vect_matrice ;
        int del = line.find(",") ;  // retourne la position du ',' s'il existe sinon -1
        int num;
        while (del != -1 ){
            string aux  ;
            aux  = line.substr(0,del) ;
            line.erase(0,del+1); // supprimer la chaine commençant de l'indice 0
            del = line.find(",") ;
            stringstream ss(aux); // conversion a string to  int
            ss >> num ;
            vect_matrice.push_back(num);

        }

        etats.push_back(vect_matrice) ;

        mat = new int*[taille];
        for(int i = 0; i < taille; i++)
            mat[i] = new int[taille];

        for ( int i = 0  ; i < vect_matrice.size()  ; i ++ )
            mat[i/taille][i%taille] = vect_matrice[i] ;
    }

    int ** get_matrice() { return mat ; }

    // FONCTION D'AFFICHAGE DE LA MATRICE
        void afficher_matrice(){
            if ( taille ==4)
       {

        cout << '\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"+---------------------------------------------------------------+" <<endl ;}
        else if (taille ==3)
            {cout << '\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"+-----------------------------------------------+" << endl ;}
        else if (taille == 5 )
            {cout << '\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"+-------------------------------------------------------------------------------+" << endl ;}
        for ( int i = 0  ; i < 2*taille   ; i ++ ){
                if (i % 2 == 0 )
                    if ( i < historique.size()){
                        cout <<"mouvement numero "<< i+1 <<"   :    "<<   historique[i] << '\t'<<"   :    |"<<'\t';

                        }
                    else {
                        cout << '\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"|"<<'\t' ;

                    }
                else
                    if ( i < historique.size()){
                        cout <<"mouvement numero "<< i+1 <<"   :    "<<   historique[i] << '\t'<<"   :    |";

                        }
                    else {
                        cout << '\t'<<'\t'<<'\t'<<'\t'<<'\t'<<"+" ;

                    }

                if ( i % 2 == 0 )
                    for ( int j = 0  ; j < taille  ; j ++ )
                    {
                      // cout << '\t\t\t\t\t\t'<<"********************************************"<<endl;
                        if (mat[i/2][j]==0)
                        {
                            cout <<' '<<'\t'<<"|"<<'\t';
                        }
                      else if ( j == taille -1 )
                        {  cout <<mat[i/2][j]<<'\t' << "|";}
                      else
                        {  cout <<mat[i/2][j]<<'\t' <<"|" <<'\t' ;}

                    }
                else{
                     if ( taille ==4)
       {

        cout <<"---------------------------------------------------------------+"  ;}
        else if (taille ==3)
            {cout <<"-----------------------------------------------+"  ;}
        else if (taille == 5 )
            {cout <<"-------------------------------------------------------------------------------+" ;}}
         cout <<'\n' ;
        }
        for (int k=taille ; k < historique.size();k++)
        {

          cout <<"mouvement numero "<< k+1 <<"   :    "<<   historique[k] << '\t'<<"   :    "<<endl ;
        }
        cout << '\n' << '\n' << '\n' ;

    }

    void afficher_etats ()
    {
         for ( int i = 0  ; i < etats[0].size()  ; i ++ ){
           cout<< etats[0][i] << " ";
       }
    }
    void ajout_historique ( int n )
    {
        historique.push_back(n) ;
    }

// **********FONCTION DE PERMUTATION
    void mouvement(int n ){
        vector<int> aux ;
        int i_n, j_n  ;
        int i_z,j_z   ;

        for ( int i = 0  ; i < taille  ; i ++ )
                for ( int j = 0  ; j < taille  ; j ++ ){
                    if (mat[i][j] == n ){
                            i_n = i  ;
                            j_n = j  ;

                    }
                }
        for ( int i = 0  ; i < taille  ; i ++ )
                for ( int j = 0  ; j < taille  ; j ++ ){
                    if (mat[i][j] == 0 ){
                            i_z = i  ;
                            j_z = j  ;

                    }
                }
       if (((i_n == i_z)&&(j_n==j_z+1))||((i_n==i_z)&&(j_n==j_z-1)) || ((i_n==i_z+1)&&(j_z==j_n)) ||((i_n==i_z-1)&&(j_z==j_n)))
      {

       ajout_historique(n);
       mat[i_n][j_n] = 0 ;
       mat[i_z][j_z] = n ;}

       for ( int i = 0  ; i < taille  ; i ++ )
            for ( int j = 0  ; j < taille  ; j ++ )
                    aux.push_back(mat[i][j]) ;

       etats.push_back(aux);

    }

//***** Fonction tester final*****
    bool tester_final ()
    {
        bool test = true ;
        for (int i=0 ; (i < taille)&& test ; i++ ){
            for (int j=0 ; (j< taille) && test  ; j++ ){
                if ((( mat[i][j] != taille*i +j + 1)&&(i != taille-1)&&(j!= taille -1))||( mat [taille-1][taille -1] != 0 ))
                    test = false ;
            }
        }

        if ( test == true )
            {
                 cout <<"                                              BRAVO !!! *_* " << endl;
                 cout<<endl;
                 cout<<endl;

            }
            else {
                  cout<<endl;
                  cout<<endl;
                 }
            return test ;

    }


//******FONCTION SAISIE NIVEAU ********

 string saisie_level( int n)
  {
    fstream file ;
    string line ;
    string fichier ;
    int j ;


     if (n==3)
       {
           cout<<"                                          ***** Niveau I ***** " <<endl ;
           cout<<endl;
           cout<<endl ;
           fichier  = "3fois3.txt" ; }
      else if (n==4)

      {
          cout<<"                                           ***** Niveau II ***** " <<endl ;
          cout<<endl ;
          cout<<endl ;

           fichier  = "4fois4.txt" ;
      }
      else
        {
        cout<<"                                              ***** Niveau III ***** " <<endl ;
        cout<<endl ;
        cout<<endl ;
           fichier  = "5fois5.txt" ;
      }

      file.open(fichier , ios::in);
      streambuf* stream_buffer_cin = cin.rdbuf();
      streambuf* stream_buffer_file = file.rdbuf();
      cin.rdbuf(stream_buffer_file);
      srand((unsigned)time(0));
      indice_line=1;//(rand() %3) +1 ;
       j=0;
      while (j!=indice_line)
      {
          cin >> line ;
          j++;
      }
      cin.rdbuf(stream_buffer_cin);

      return line ;
  }
  // *******FONCTION SOLUTION******
  void aide (int n , string nom  )
  {
       fstream file ;
       string line,line1,line2 ;
       string fichier ;
       char c;
       cout << "    *si vous voulez une aide appuyez sur h "<<endl ;
       cout<<endl;
       cout << "    *si vous n'avez pas besoin d'aide appuyez sur n"<<endl;
       cout<<endl;
       cout<<"    *si vous voulez quitter le jeu appuyez su q "<<endl;
       cout << endl ;
       do{
            cout<<"       ";
           cin>>c ;
       }while ((c!='H')&&(c!='h')&&(c!='N')&&(c!='n')&&(c!='Q')&&(c!='q'));
          if ((c=='H')||(c=='h'))

          {
                if (n==3)
                   {
                        fichier ="3.txt";

                   }
                else if (n==4)
                   {
                         fichier="4.txt";
                   }
                else if (n==5)
                   {
                         fichier="5.txt";
                   }

                 file.open(fichier , ios::in);
                 streambuf* stream_buffer_cin = cin.rdbuf();
                 streambuf* stream_buffer_file = file.rdbuf();
                 cin.rdbuf(stream_buffer_file);

                 int j=0;
                 while (j!=indice_line)
                 {
                   cin >> line ;
                   j++;
                 }


                 cin.rdbuf(stream_buffer_cin);

         cout<<endl;
         cout << "     VOICI les nombres que vous pouvez deplacer pour atteindre l'etat final "<<endl;
         cout<<endl;
         cout<<"         ";
         cout<<line<< endl;
         quitter_while=true ;}
         else if ((c=='q')||(c=='Q') )
         {
          quitter_while=true ;
         enregistrer_ancienne_partie( nom);
         }

        }

      //*******FONCTION ENREGISTRER ANCIENNE PARTIE*********

 void enregistrer_ancienne_partie(string nom){
 string ligne ;
 multimap<string,string> fichier;
 string name;
 string matrice ;

ifstream ancienne("anciennes_parties.txt");

while(getline(ancienne, ligne)){
    ancienne>> name  ;
    ancienne>> matrice ;
    if ( name != nom )
        fichier.insert(pair<string,string>(name,matrice));
}
ancienne.close();

ofstream nouvelle("anciennes_parties.txt",ios::out);

if(nouvelle){
   nouvelle<<nom<<" ";
   for ( int i = 0  ; i <etats[etats.size()-1].size();i++){
       nouvelle<<etats[etats.size()-1][i]<<",";
       }

nouvelle<<endl;
for (std::multimap<string,string>::iterator it=fichier.begin(); it!=fichier.end(); ++it)
    nouvelle << (*it).first << " " << (*it).second << '\n';

    nouvelle.close();  // on referme le fichier
        }
        else  // sinon
                cout << "Erreur à l'ouverture !" << endl;
}



};

class Joueur
{
private:
    string Utilisateur;
    long long Score;
public:
//getters

  string get_utilisateur(){return(Utilisateur);}
  long long  get_score(){return(Score);}
//setters

void set_score(long long s){Score = s;}
//constructeus
Joueur()
{
    Utilisateur="Nouveau";
}

Joueur(string Utilisateur1,long long Score1){

Utilisateur=Utilisateur1;

Score=Score1;
}

Joueur(string Utilisateur1){
Utilisateur=Utilisateur1;

Score=0;
}
 void Tab_Joueurs(){
    multimap<long long,string> top_joueurs;
     multimap <long long, string> :: iterator m1_Iter;
   multimap <long long, string> :: const_iterator m1_cIter;

    //écrire dans un fichier la liste des joueurs avec leurs scores

ifstream fichier1("liste_joueurs.txt" );  //déclaration du flux et ouverture du fichier

        if(fichier1)  // si l'ouverture a réussi
        {
            string nom,ligne;
            long long score;
             int i=0;
         //fichier1>>ligne1>>ligne12;
        while(getline(fichier1, ligne)&& i<=6)  {// tant que l'on peut mettre la ligne dans "ligne"||5 top
        i++;
            fichier1>>nom;
           fichier1>>score;
           //cout<<nom<<score<<endl;
           if(nom==this->Utilisateur){
             if((this->Score)>score)
                this->Score=score;
             }
           else
            top_joueurs.insert(pair<long long,string>(score,nom));

    }

fichier1.close();  // on referme le fichier
        }
        else  // sinon
                cout << "Erreur à l'ouverture !" << endl;
  top_joueurs.insert(pair<long long,string>(this->Score,this->Utilisateur));
ofstream fichier2("liste_joueurs.txt");

if(fichier2){
        fichier2<<"                                 **************Top_Joueurs************"<<endl;

     for(int j=0;j<=top_joueurs.size()+3;j++){
    m1_cIter = top_joueurs.begin ( );
 fichier2 << m1_cIter -> second <<" "<<  m1_cIter -> first<< endl;

   m1_Iter = top_joueurs.begin ( );
   top_joueurs.erase ( m1_Iter );}
fichier2.close();  // on referme le fichier
        }
        else  // sinon
                cout << "Erreur à l'ouverture !" << endl;



    }


 void Affiche_Rang(){
//lire à partir d'un fichier la liste des joueurs
ifstream fichier2("liste_joueurs.txt");  // on ouvre le fichier en lecture
        if(fichier2)  // si l'ouverture a réussi
        {        string ligne,name;
                 int i=1;
                 long long tscore;
getline(fichier2, ligne);
cout<<ligne<<endl;

        while(i<=5){

               fichier2>>name;
               fichier2>>tscore;
                cout <<"                                      Le "<<i<<" est "<<name<<" avec score  "<<tscore<<endl;
        i++;
                }
                fichier2.close();
        }
        else
                cout << "Impossible d'ouvrir le fichier !" << endl;
  }


 string afficher_ancienne_partie(string nom){
    ifstream aff_ancienne("anciennes_parties.txt" );  //déclaration du flux et ouverture du fichier

        if(aff_ancienne)  // si l'ouverture a réussi
        {
            string name,line1,contenu;

          do {

            aff_ancienne>>name;
            aff_ancienne>>line1;
            }while(getline(aff_ancienne, contenu)&&(nom!=name));




      aff_ancienne.close();
      if(nom==name)

         return(line1); }

        else  // sinon
                cout << "Erreur à l'ouverture !" << endl;


}


string Saisie_Joueur(string nom,string reponse){
string chaine="nouvelle_partie";
cout<<endl;

cout<<"  Saisir votre nom :"<<endl;
cin>>nom;
Utilisateur=nom;
reponse=chaine;
ifstream fichier3("liste_joueurs.txt");  // on ouvre le fichier en lecture

        if(fichier3)  // si l'ouverture a réussi
        {        string ligne,name;
                 long long tscore;
         // déclaration d'une chaîne qui contiendra la ligne lue
        while(getline(fichier3, ligne)){

               fichier3>>name;
               fichier3>>tscore;
          if (name==nom){
                string rep;


                while((rep!="oui")&&(rep!="non"))
                {
                     cout <<"  Si vous-voulez continuer votre partie ecrire 'oui' sinon ecrire 'non' :"<<endl;
                cin  >>rep;
                }

               if(rep=="non")
                {reponse="ancien_joueur_nouvelle_partie";}
               else{ reponse="continuer";}


               }

                }
                fichier3.close();
                 return reponse;
        }
        else
                cout << "Impossible d'ouvrir le fichier !" << endl;

    }


};

int main()
{ system ("color  3F" );
    int votre_choix;
    menu jeu;

    Joueur joueur ;

    Matrice notre_matrice ;

    int num_dep;
    int taille_mat;
    string nom;
    string reponse;

    string rep;
    string line;

    cout<<endl;
    cout<<endl;
    cout<<"             ***************Bienvenu au Jeu-Taquin****************"<<endl;
    cout<<endl;
    cout<<endl;

    jeu.ajout();
    jeu.facile();
    jeu.moyen();
    jeu.difficile();
    jeu.prop();




    jeu.choix();

    do
    {
        cin >> votre_choix;

    }while ((votre_choix!=0) &&(votre_choix!=4));

        if (votre_choix==4)
            {
               rep=joueur.Saisie_Joueur(nom,reponse);
              if((rep=="nouvelle_partie")||(rep=="ancien_joueur_nouvelle_partie"))
                {
                jeu.choix2();
                do
                {
                     cin >>votre_choix;

                }while (  (votre_choix!=3)&&(votre_choix!=4)&& (votre_choix!=5)) ;



                }
        else if(rep=="continuer"){

            line=joueur.afficher_ancienne_partie(joueur.get_utilisateur());

            if(line.length()==38)
                  {taille_mat=4;
}
            if (line.length()==18)

                  {taille_mat=3;}
            if (line.length()==65)
                  {taille_mat=5;}


                notre_matrice.set_taille(taille_mat);
                notre_matrice.set_matrice(line) ;

                }

            }

        if (votre_choix==0){
            cout<<""<<endl;
            cout << "Ce jeu consiste a remettre dans l'ordre les N carreaux a partir d'une configuration initiale ";
            cout <<"quelconque tout en effectuant un nombre minimal de mouvements ." <<endl;
            cout<<endl ;
            cout<<"    *Tapez 4 pour saisir joueur "<<endl;
            cout<<endl;

             do
             {
            cout<<"     ";
               cin >>votre_choix;

              }while ( (votre_choix!=4));


            if (votre_choix==4)
               {
                 rep=joueur.Saisie_Joueur(nom,reponse);
              if((rep=="nouvelle_partie")||(rep=="ancien_joueur_nouvelle_partie"))
                {
                jeu.choix2();
                do
                {
                     cin >>votre_choix;

                }while (  (votre_choix!=3)&&(votre_choix!=4)&& (votre_choix!=5)) ;


                }}}

         if (votre_choix!=0) {
            if ( rep != "continuer")
               {

                line = notre_matrice.saisie_level(votre_choix);
               notre_matrice.set_taille(votre_choix);}
        else{ notre_matrice.set_taille(taille_mat);}
        notre_matrice.set_matrice(line) ;
        notre_matrice.afficher_matrice() ;
        auto t_start=chrono::high_resolution_clock::now() ;

         while ( (notre_matrice.tester_final()!=true  )&&(notre_matrice.get_quitter_while()==false))
        {
             cout<<endl ;
             cout<<endl ;
             notre_matrice.aide(votre_choix,joueur.get_utilisateur());
             cout<<endl;
             cout<<endl;
             if(notre_matrice.get_quitter_while()==false)
            {
              cout<<endl;
             cout << "     * Entrer le numero a deplacer * : " ;
             cin >> num_dep ;
             cout<<endl;
             cout<<endl;
             notre_matrice.mouvement(num_dep);

             notre_matrice.afficher_matrice() ;
             cout<<endl ;
             cout<<endl ;}

        }
     if (notre_matrice.get_quitter_while()==false){
       auto t_end=chrono::high_resolution_clock::now();
        double elapsed_time_ms = chrono::duration< double,std::milli>(t_end-t_start).count();
         long long score=(long long)elapsed_time_ms;
       cout<<"                                          votre score est : "<<score ;


       cout<<endl;
       cout<<endl;
       cout<<endl;
     joueur.set_score(score);
       joueur.Tab_Joueurs();
       joueur.Affiche_Rang();}
       else {
         cout << "                     Merci pour votre participation *_*  " <<endl ;
         cout<<endl;
         cout<<endl ;

       }


    }


    return 0;
}
