#include <iostream>
using namespace std;

int main(void){
	//Altere estes valores para mudar a palavra ou o limite de tentativas.
	const char palavra_certa[] = "caderno";
	int tentativas = 3;

	//A partir daqui só altere se souber o que está fazendo.
	char palavra[sizeof(palavra_certa)];
	for(int i=0; i<sizeof(palavra_certa)-1; i++){
		palavra[i] = '_';
	}
	char palpite;	
	bool acertou = false;
	
	cout << "\n=======================================\n";
	cout << "Bem-vindo ao jogo de forca!" << "\n\n"; 
	cout << "ATENÇÃO: APENAS USE LETRAS MINÚSCULAS! \n";
	while(!acertou && tentativas > 0){
		cout << "\nPalavra: " << palavra << "\n";
		cout << "Você tem: " << tentativas << " tentativas Antes do boneco morrer \n";
		cout << "\nDê seu palpite: ";
		cin >> palpite;	

		for(int i=0; i<sizeof(palavra_certa); i++){
			if(palpite == palavra_certa[i] && palpite != palavra[i]){
				palavra[i] = palpite;
				cout << "Parabéns! Você acertou a letra! \n\n";
				break;
			}else if(i == sizeof(palavra_certa)-1 && palpite != palavra_certa[i]){
				cout << "Que pena, você errou! \n\n";
				tentativas--;
			}
		}

		for(int i=0; i<sizeof(palavra_certa); i++){
			if(palavra[i] == palavra_certa[i]){	
				if(i == sizeof(palavra_certa) - 2){
					cout << "Parabéns! Você venceu!" << '\n';
					acertou = true;
				}
			}else{
				break;
			}
		}
	}
	cout << "\n=======================================\n";
	return 0;
}
