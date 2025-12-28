#include <stdio.h>

// fonction pour calculer l'interet
double calculinteret(double capital,double taux, int nbrj){    //nbrj:nombre de jours
    double interet;
    interet=(capital*taux*nbrj)/36000;
    return interet;

}
int main(){
    printf("==== programme de calcul des interets simples ====\n");
    int choix;
    do {
        printf("\n Menu:\n");
        printf("1.Calculer interets simples pour un capital et un nombre de jours\n");
        printf("2.Calculer interets cumules sur plusieurs periodes\n");
        printf("3.quitter\n");
        printf("entrez votre choix: ");
        scanf("%d",&choix);
        switch (choix){
            case 1:{
                double capital,taux,impot;
                int nbrj;
                do{
                    printf("saisir le capital: ");
                    scanf("%lf",&capital);
                }while (capital<0);

                do{
                    printf("entrez le taux annuel en pourcentage: ");
                    scanf("%lf",&taux);
                }while (taux<0);

                do{
                    printf("entrez le nombre de jours: ");
                    scanf("%d",&nbrj);
                }while (nbrj<0);

                do{
                    printf("entrez le taux d impot: ");
                    scanf("%lf",&impot);                // impot ici c est le taux d'impot

                }while (impot<0);

                double interet_brut =calculinteret(capital,taux,nbrj);
                double interet_net=interet_brut*(1-impot/100);
                double capital_finale=interet_net+capital;
                break;

            }
            case 2:{

                double capital,taux,impot;
                int nbrj,periodes;              //ici je veux calculer les interet sur des periodes consecutifs (plusieus operation) don c'est la difference entre case 1 et case 2
                do{
                    printf("saisir le capital: ");
                    scanf("%lf",&capital);
                }while (capital<0);

                do{
                    printf("entrez le taux annuel en pourcentage: ");
                    scanf("%lf",&taux);
                }while (taux<0);
                
                do{
                    printf("entrez le taux d impot: ");
                    scanf("%lf",&impot);               

                }while (impot<0);

                do{
                    printf("entrez le nombre de periodes: ");
                    scanf("%d",&periodes);
                }while(periodes<0);
                
                double interet_brut;
                double interet_net;
                double capitalfinale=capital;

                int i;
                for (i=1;i<=periodes;i++){
                    do{
                        printf("Entrez le nombre de jours pour la periode %d: ",i);
                        scanf("%d",&nbrj);
                    }while (nbrj<0);

                    
                    interet_brut =calculinteret(capital,taux,nbrj);
                    interet_net=interet_brut*(1-impot/100);
                    capitalfinale += interet_net;
                    printf("Periode %d: Interet brut = %lf, Interet net = %lf, Capital final = %lf\n",i, interet_brut, interet_net, capitalfinale);
                    printf("------------------------------------------------------------------------\n");
                
                    
                }
            break;
                

            }
            case 3:
                printf("Merci d avoir utiliser le programme\n");
                break;

            default:
                printf("Choix invalide, veuillez reessayer.\n");
            break;

        }

    }while(choix!=3);

    return 0;
}