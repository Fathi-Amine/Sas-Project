#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Struct Of Date
struct date{
	int day, month, year;
};

//struct Of product details

struct Details{
	char name[30];
	int  code, quantity; 
	float price, prixTTC;
	
};

struct PurchasedItems{
	char name[50];
	int purchasedCode, purchasedQuantity;
	float priceOfPurchase,pPrice;
	struct date dop;
	
};
struct Details item[60];
struct PurchasedItems purchased[60];
/* run this program using the console pauser or add your own getch, system("pause") or input loop */


// Print functions
void showMenu();
void addProductToInventory();
void showListOfProducts();
void sortListAlphabetically();
void sortListByPrice();
void purchaseItem();
void searchByCode();
void stockStatus();
void stockSupply();
void deleteItem();
void totalSells();
//Logic Functions


int pCounter = 0;
int tracer = 0;
int purchaseTracer = 0;
int numOfPurchases = 0;
float Min =0;
float Max =0;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	showMenu();
	return 0;
}

//Print functions 
void showMenu(){
	int index;
	do {
		printf("1/- Ajouter un medicament. \n");
		printf("2/- Rechercher. \n");
		printf("3/- Supprimer. \n");
		printf("4/- Afficher les produits en stock. \n");
		printf("5/- Acheter un medicament \n");
		printf("6/- Alimenter le stock. \n");
		printf("7/- Statistique. \n");
		printf("8/- Exit. \n");
		scanf("%d", &index);
		system("cls");
		switch(index){
			case 1: addProductToInventory();
					break;
			
			case 2: searchByCode(item);
					break;
			
			case 3: deleteItem();
					break;
			
			case 4: showListOfProducts();
					break;
				
			case 5: purchaseItem(item);
					break;
					
			case 6: stockSupply();
					break;
					
			case 7: totalSells();
					break;
						
			case 8: exit(0);
					break;
					
			default: printf("You entered a wrong number \n Please Try again");
					break;
			
		}
	}while(index > 5);
}

// La fonction pour ajouter un produit
void addProductToInventory(){
	//struct Details item[60];
	int n, i,j, choice, matchingCodes = 0;
	printf("Entrer le nombre des produits a ajouter : \n");
	scanf("%d", &n);
	fflush(stdin);
	for(i = tracer; i < n + tracer; i++){
		fflush(stdin);
		printf("Le code de medicament : \n");
		scanf("%d", &item[i].code);
		fflush(stdin);
		
		fflush(stdin);
		printf("Le nom de medicaments: \n");
		scanf("%s", item[i].name);
		fflush(stdin);
		
		fflush(stdin);
		printf("La quantite : \n");
		scanf("%d", &item[i].quantity);
		fflush(stdin);
		
		fflush(stdin);
		printf("Prix : \n");
		scanf("%f", &item[i].price);
		fflush(stdin);
		
		item[i].prixTTC = item[i].price + (item[i].price * 15/100);
		pCounter++;
		printf("%d", pCounter);
	}
	tracer+=n;
	system("cls");
	
	getch();
	showMenu();
	
}

void showListOfProducts(){
	int i, sort;
	printf("\t \t \t \t \t*** STOCK DES MEDICAMENTS *** \n");
	for(i = 0; i<pCounter; i++){
		printf("\t \t \t ---------------------------------------------------------------------\n");
		printf("\t \t \t Le nom de medicament : %s \n", item[i].name);
		printf("\t \t \t Le code de medicament : %d \n", item[i].code);
		printf("\t \t \t La quantite en stock : %d \n", item[i].quantity);
		printf("\t \t \t Le prix HT : %.2f \n", item[i].price);
		printf("\t \t \t Le prix TTC : %.2f \n", item[i].prixTTC);
		printf("\t \t \t ---------------------------------------------------------------------\n");
	}
	printf("Voulez vous trier la liste des medicament ?\n 1 pour trier en ordre alphabetique \n 2 pour trier par prix");
	scanf("%d", &sort);
	if(sort == 1){
		sortListAlphabetically();
		showMenu();
	}else if(sort == 2){
		sortListByPrice();
		showMenu();
	}else {
		showMenu();
	}
	getch();
	
}

void sortListAlphabetically(){
	struct Details tempItem[1];
	int i, j;
	for(i=0;i<pCounter;i++){
      for(j=i+1;j<pCounter;j++){
         if(strcmp(item[i].name,item[j].name)>0){
            tempItem[0]= item[i];
            item[i] = item[j];
            item[j] = tempItem[0];
         }
      }
   }
   for(i = 0; i<pCounter; i++){
		printf("%d            %s                     %d                    %d              %.2f \n", i+1, item[i].name, item[i].code, item[i].quantity, item[i].price);
		printf("==========================================================================================\n");
	}
	
}

// Sort By Price Function
void sortListByPrice(){
	struct Details tempItem[1];
	int i, j;
	for(i=0;i<pCounter;i++){
      for(j=i+1;j<pCounter;j++){
         if(item[i].price < item[j].price){
            tempItem[0]= item[i];
            item[i] = item[j];
            item[j] = tempItem[0];
         }
      }
   }
   for(i = 0; i<pCounter; i++){
		printf("%d            %s                     %d                    %d              %.2f \n", i+1, item[i].name, item[i].code, item[i].quantity, item[i].price);
		printf("==========================================================================================\n");
	}
}

// Purchase Function

void purchaseItem(){
	int numOfOrders;
	int i, j;
	printf("How many medicaments you wanna purchase");
	scanf("%d", &numOfOrders);
	//struct PurchasedItems purchased[numOfOrders];
	for(i = 0; i < numOfOrders; i++){
		fflush(stdin);
		printf("Veuillez entrer le code du medicament: \n");
		scanf("%d", &purchased[i].purchasedCode);
		fflush(stdin);
		
		fflush(stdin);
		printf("Veuillez entrer la quantite achetee : \n");
		scanf("%d", &purchased[i].purchasedQuantity);
		fflush(stdin);
		
		fflush(stdin);
		printf("Veuillez entrer la date d'achat(jj-mm-aaaa): \n");
		scanf("%d-%d-%d", &purchased[i].dop.day,&purchased[i].dop.month, &purchased[i].dop.year);
	}
	for(i = 0; i < pCounter; i++){
		for(j = 0; j < numOfOrders; j++){
			if(item[i].code == purchased[j].purchasedCode){
				item[i].quantity = item[i].quantity - purchased[j].purchasedQuantity;
				strcpy(purchased[j].name ,item[i].name);
				purchased[j].pPrice = item[i].price;
				purchased[j].priceOfPurchase =  purchased[j].pPrice + (purchased[j].pPrice * 15/100);
				numOfPurchases++;
				
				if(Max < purchased[j].priceOfPurchase)
				
						Max = purchased[j].priceOfPurchase;
						
				if(Min > purchased[j].priceOfPurchase || Min == 0)
				
						Min = purchased[j].priceOfPurchase;
				
			}
		}
	}
	
	
	showMenu();
}

// Search By quantity and Code

void searchByCode(){
	int code, found = 0, choose, quantity;
	int i, j;
	printf("Voulez vous rechercher par code our par quantite ??\n Choisissez 1 pour la recherche par code et 2 pour la recherche par quantité et 3 pour rechercher les stocks en rupture \n");
	scanf("%d", &choose);
	if(choose == 1){
		printf("Veuillez entrer le code de medicament voulez vous rechercher");
		scanf("%d", &code);
	}else if(choose == 2){
		printf("Veuillez entrer la quantité de medicament voulez vous rechercher");
		scanf("%d", &quantity);
	}else if(choose == 3){
		found = 1;
		stockStatus();
	}
	
	
	for(i = 0; i < pCounter; i++){
		if(item[i].code == code || item[i].quantity == quantity){
			printf("%s \n", item[i].name);
			printf("%d \n", item[i].code);
			printf("%d \n", item[i].quantity);
			printf("%.2f \n", item[i].price);
			found = 1;
		}
	}
	if(found == 0){
		printf("medicament introuvable. \n");
	}
	showMenu();
}

// Stock status Function

void stockStatus(){
	int i, threeItemsOrLess = 0;
	for(i = 0; i < pCounter; i++){
		if(item[i].quantity < 3){
			printf("%s \n", item[i].name);
			printf("%d \n", item[i].code);
			printf("%d \n", item[i].quantity);
			printf("%.2f \n", item[i].price);
			threeItemsOrLess++;
		}
	}
	
	if(threeItemsOrLess == 0){
		printf("Il y a pas d'element en stock dont la quantite est inferieure a 3 \n");
	}
	
}

// Supply stock and update it function

void stockSupply(){
	int i, code, quantity;
	printf("Veuillez entrer le code de medicament a alimenter :");
	scanf("%d", &code);
	printf("Veuillez entrer la quantite : ");
	scanf("%d", &quantity);
	for(i = 0; i < pCounter; i++){
		if(item[i].code == code){
		item[i].quantity += quantity;
		}
	}
}


// Delete Item Function 

void deleteItem(){
	int i,j, itemCode, tOrF = 0;
	
	printf("Veuillez entrer le code de medicament souhaitez vous supprimer");
	scanf("%d", &itemCode);
	for(i = 0; i < pCounter; i++){
		if(item[i].code == itemCode){
			for(j = i; j < pCounter; j++){
				item[j] = item[j+1];
				tOrF++;
			}
			printf("\n medicament supprime");
			pCounter--;
			tracer--;
		}
		
	}
	
	if(tOrF == 0){
		printf("Il y aucune medicament avec ce code");
	}
	showMenu();
}

// Sold Products Total Function

void totalSells(){
	int i;
	float total = 0, soldProduct, la_moyenne;
	for(i = 0; i <= numOfPurchases; i++){
		soldProduct = purchased[i].priceOfPurchase * purchased[i].purchasedQuantity;
		total = total + soldProduct;
	}
	for(i = 0; i<numOfPurchases; i++){
		/*printf("%s                     %d                    %d              %d                 %d           %d/%d/%d\n", purchased[i].name, purchased[i].purchasedCode, purchased[i].purchasedQuantity, purchased[i].pPrice, purchased[i].priceOfPurchase, purchased[i].dop.day, purchased[i].dop.month,purchased[i].dop.year);
		printf("==========================================================================================\n");
			printf("\t \t \t ---------------------------------------------------------------------\n");*/
		printf("\t \t \t Le nom de medicament : %s \n", purchased[i].name);
		printf("\t \t \t Le code de medicament : %d \n", purchased[i].purchasedCode);
		printf("\t \t \t La quantite en stock : %d \n",  purchased[i].purchasedQuantity);
		printf("\t \t \t Le prix HT : %.2f \n", purchased[i].pPrice);
		printf("\t \t \t Le prix TTC : %.2f \n", purchased[i].priceOfPurchase);
		printf("\t \t \t Total d'achat' : %.2f \n", soldProduct);
		printf("\t \t \t La date d'achat' : %d/%d/%d \n", purchased[i].dop.day, purchased[i].dop.month,purchased[i].dop.year);
		printf("\t \t \t ---------------------------------------------------------------------\n");
	}
	la_moyenne = total/numOfPurchases;
	printf("%.2f \n", total);
	printf("%.2f \n", la_moyenne);
	printf("%.2f \n", Max);
	printf("%.2f \n", Min);
}
