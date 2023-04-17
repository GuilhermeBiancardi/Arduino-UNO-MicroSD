/**
 * MicroSD 5v
 */

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

#define pinCS 10
#define pinSCK 13
#define pinMOSI 11
#define pinMISO 12

File myFile;

void setup() {
    
    Serial.begin(9600);
    pinMode(pinCS, OUTPUT);

    if (SD.begin(pinCS)) {
        Serial.println("SD Card pronto para uso.");
    } else {
        Serial.println("Falha na inicialização do SD Card.");
        return;
    }

    myFile = SD.open("teste.txt", FILE_WRITE);
    
    if (myFile) {
        Serial.println("Escrevendo no Arquivo .txt");
        // Gravo isso no arquivo
        myFile.println("Texto a ser Gravado UHULLL");
        // Fecho o arquivo
        myFile.close();
        Serial.println("Terminado.");
        Serial.println(" ");
    } else {
        Serial.println("Erro ao Abrir Arquivo .txt");
    }

    myFile = SD.open("teste.txt");

    if (myFile) {
        Serial.println("Conteúdo do Arquivo:");
        while (myFile.available()) {
            Serial.write(myFile.read());
        }
        myFile.close();
    } else {
        Serial.println("Erro ao Abrir Arquivo .txt");
    }

}

void loop() {}

/*

SD.begin(pinCS) // Inicia o cartão SD
SD.exists("filename") // Verifica se o arquivo existe
SD.open("filepath", mode) // Abre o arquivo do modo desejado
SD.close() // Fecha o arquivo atual
SD.remove("filename") // Apaga o arquivo
SD.mkdir("foldername") // Cria um diretório no cartão
SD.name() // Retorna o nome do arquivo atual
SD.print(data) // Escreve na mesma linha
SD.println(data) // Escreve e pula linha
SD.read() // Lê o arquivo
SD.avaliable() // Checa se existe espaço para escrita no arquivo

*/