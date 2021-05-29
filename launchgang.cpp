#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;


class incubateur
{
    private :
    string nom;
    string identifiant;

    public :
    //incubateur();
    //incubateur(string nom,string identifiant);
    void affiche()const
    { cout << nom <<endl;
	  cout << identifiant<<endl ;

	};
    void saisir()
    { cout<<"donner le nom"<<endl;
	  cin >> nom ;
	  cout<<"Donner votre identifiant"<<endl;
      cin >> identifiant ;

	};
    string getNom()const
    { return ( nom );
	};
	string getidentifiant()const
	{ return (identifiant);
	};

    bool operator== (incubateur &p) const
    { return ((p.nom==nom)&&(p.identifiant==identifiant));
	};
	void creercompte (incubateur&p)
	{ p.saisir();
	};
    bool inscription()
    { cout << "Voulez-vous inscrire ? O/N"<<endl ;
      bool rep;
      char ans;
      cin >> ans ;
      rep = ( ans=='O'|| ans =='o');
      if (rep)
      { saisir();}
      else
      { cout << " Le Compte existe déjà" ;
	  } ;




	  };
	};
class domaine
{ public :
    string nomdudomaine ;
  public :
  	domaine ( string nomdudomaine );
  	void affiche () const
  	{ cout << " Saisir le domaine du projet que vous désirez le présenter ou l'accompagner " ;
	  };
	void afficher() const {}
    void saisir ()
    { cin >> nomdudomaine ;
	};
	istream & operator << (istream & nomdudomaine ) {

       return nomdudomaine ;};
    ostream& operator >> (ostream & nomdudomaine){

	};




} ;
class porteurdeprojet
{
    public :
    string nom;
    string prenom;
    string age;
    string Domaine;
    string presentation;
 
    public :
    void affichepp()const
    { cout << nom<<endl;
      cout << prenom<<endl;
      cout << age<<endl;
      cout<< Domaine<<endl;
      cout<<presentation<<endl;
	};
    void saisirpp()


    { cout<<"Donner votre nom"<<endl ;
	 cin >> nom;
	 cout <<"Donner votre prenom"<<endl;
      cin >> prenom;
    cout<<"Donner votre age"<<endl;
      cin >> age;
    do{
    cout<<"Saisir votre domaine:informatique/architecture"<<endl;
	cin>>Domaine;}
	while ((Domaine!="informatique")&&(Domaine!="architecture"));
	cout<<"Presenter Votre Projet"<<endl;
	cin>>presentation ;


	};
    string getNompp()const
    { return (nom );
	};
    string getPrenompp()const
    { return (prenom);
	};
    string getAgepp()const
    { return (age);
	};
    bool operator == (porteurdeprojet &pp) const
    { return ((pp.nom==nom)&&(pp.prenom==prenom)&&(pp.age==age));
	};

};



class projet : public  domaine
{ private :
    string nomprojet;
    string description;
    domaine A;
  public :
    projet( string nomdudomaine );
    string getNomprojet()const
    {
        return(nomprojet);
    };
    string getDescription()const
    {
        return(description);
    };
    domaine getA()const
    {
        return(A);
    };

  	void affiche ()

  	{ domaine::affiche();
	  cout <<"Le nom du projet:"<< nomprojet;
  	  cout << "Introduction:"<< description;
  	  //cout <<"le domaine du projet est:"<<A;
	  };
    void saisir ()

    { domaine::affiche() ;
	  cin >> nomprojet;
      cin >> description;
      //cin >> A;
	};



} ;
class investisseur {
    private :
         string nom, prenom, domaine , domaineinvestissement ;

    public :
        //investisseur();
        //investisseur ( string x,string y,string z,string w) {
        //nom=x;
        //prenom=y;
        //domaine=z;
        //domaineinvestissement=w;

        void afficher () const { cout<<nom;
        cout<<prenom<<endl;
        cout<<domaine<<endl;
        cout<<domaineinvestissement<<endl;

        }
        void saisir (){
            cout<<"saisir votre nom et prenom , votre domaine , votre domaine d'investissement desire"<<endl;
            cin>>nom;
            cin>>prenom;
            cin>>domaine ;
            cin>>domaineinvestissement ;
        }






};
int main(){
 int nbrLigne1= 0;
 int nbrLigne2= 0;
 int nbrLigne3= 0;
 int identification ;
 string rep1;
 string presentation , Domaine , conseil ;
 
  do{

 cout<<"Identifiez-vous"<<endl;
 cout<<"1-investisseur 2-porteur de projet 3-incubateur"<<endl;
 cin>>identification ; }
 while ((identification!=1)&&(identification!=2)&&(identification!=3));

  switch (identification){

   case 1:

	{ investisseur inv ; 
	  inv.saisir();
	  inv.afficher(); 
	cout<<"voulez vous consulter la liste des projets? oui/ non"<<endl;
    cin>>rep1;
    if (rep1=="oui"){
        ifstream mabase("E:\\Lauunchgaang\\porteurdeprojet.txt");
        if(mabase)
        {
            string l;
            while(getline(mabase, l))
            {
                cout<<l<<endl;
            }
        }
        else{
            cout<<"ERREUR: Impossible douvrir le fichier en lecture "<<endl;

        };
    } ;
};
     break;
   case 2:
   	{
	
   	string const nomFichier1("E:\\Lauunchgaang\\porteurdeprojet.txt");
	ofstream mabase(nomFichier1.c_str(), ios::app);
	if (mabase){
            	porteurdeprojet p ;
                p.saisirpp();
                p.affichepp();
                mabase<< p.nom <<":"<< p.prenom<<":"<<p.age<<":"<<p.Domaine<<":"<<p.presentation<<endl;
                nbrLigne1++;}
    else
    {
        cout<< "ERREUR: Impossible d'ouvrir le fichier."<<endl;
    }
    cout<<"voulez vous consulter la liste des projets? oui/ non"<<endl;
    cin>>rep1;
    if (rep1=="oui"){
        ifstream mabase("E:\\Lauunchgaang\\porteurdeprojet.txt");

        if(mabase)
        {
            string l;
            while(getline(mabase, l))
            {
                cout<<l<<endl;
            }
        }
        else{
            cout<<"ERREUR: Impossible douvrir le fichier en lecture "<<endl;

        };
    };

	};
   	  break ;
   case 3 :
   	{incubateur inc ;
   	inc.saisir();
	inc.affiche();
	cout<<"voulez vous consulter la liste des projets? oui/ non"<<endl;
    cin>>rep1;
    if (rep1=="oui"){
        ifstream mabase("E:\\Lauunchgaang\\porteurdeprojet.txt");

        if(mabase)
        {
            string l;
            while(getline(mabase, l))
            {
                cout<<l<<endl;
            }
        }
        else{
            cout<<"ERREUR: Impossible douvrir le fichier en lecture "<<endl;

        };
    };


};
    	break ;
};
}





