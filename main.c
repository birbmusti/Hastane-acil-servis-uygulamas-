#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATIENTS 100

typedef struct {
    int id;
    char name[50];
    int age;
    char condition[100];
    int priority; // 1-5 arasinda triage seviyesi
    int prescription_no;
} Patient;

Patient patients[MAX_PATIENTS];
int patient_count = 0;
int prescription_counter = 1000; // Recete numaralarini uretmek icin baslangic

void generate_hl7_message(Patient p, char *hl7_message) {
    sprintf(hl7_message,
            "MSH|^~\&|HOSPITAL_SYS|ER|RECEIVING_SYS|LAB|%d||ADT^A01|%d|P|2.3\n"
            "PID|1||%d^^^HOSP_ID||%s||%d||%s\n"
            "PV1|1|E|||||ER_DOCTOR|||||||||||||ER\n",
            p.id, p.id, p.id, p.name, p.age, p.condition);
}

void add_patient() {
    if (patient_count >= MAX_PATIENTS) {
        printf("Hasta listesi dolu!\n");
        return;
    }
    
    Patient p;
    p.id = patient_count + 1;
    
    printf("Hasta adi: ");
    scanf(" %[^\n]", p.name);  // Satır atlayana kadar oku
    
    printf("Yas: ");
    scanf("%d", &p.age);
    
    // Girdi tamponunu temizle
    while (getchar() != '\n');
    
    printf("Hastalik durumu: ");
    scanf(" %[^\n]", p.condition);  // Satır atlayana kadar oku
    
    printf("Oncelik (1-5): ");
    scanf("%d", &p.priority);
    
    // Oncelik Dogrulama
    if (p.priority < 1 || p.priority > 5) {
        printf("Gecersiz oncelik! 1-5 arasinda olmali.\n");
        p.priority = 5; //Varsayılan olarak en düşük önceliğe ayarla
    }
    
    p.prescription_no = prescription_counter++;
    
    patients[patient_count++] = p;
    printf("Hasta basariyla kaydedildi! Hasta ID: %d, Recete No: %d\n", p.id, p.prescription_no);
}

void list_patients() {
    if (patient_count == 0) {
        printf("Kayitli hasta bulunmamaktadir.\n");
        return;
    }
    printf("\n--- HL7 Formatinda Hasta Listesi ---\n");
    for (int i = 0; i < patient_count; i++) {
        char hl7_message[512];
        generate_hl7_message(patients[i], hl7_message);
        printf("%s\n", hl7_message);
    }
}

void emergency_queue() {
    // Oncelik sirasina gore hastalari siralama (bubble sort kullanilarak basit bir siralama)
    for (int i = 0; i < patient_count - 1; i++) {
        for (int j = 0; j < patient_count - i - 1; j++) {
            if (patients[j].priority > patients[j + 1].priority) {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
    printf("\nHastalar aciliyet sirasina gore siralandi!\n");
    list_patients();
}

int main() {
    int choice;
    while (1) {
        printf("\nAcil Servis Yonetim Sistemi\n");
        printf("1. Hasta Ekle\n");
        printf("2. Hastalari Listele (HL7 Formatinda)\n");
        printf("3. Aciliyet Sirasina Gore Listele\n");
        printf("4. Cikis\n");
        printf("Seciminizi yapin: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                add_patient();
                break;
            case 2:
                list_patients();
                break;
            case 3:
                emergency_queue();
                break;
            case 4:
                exit(0);
            default:
                printf("Gecersiz secim!\n");
        }
    }
    return 0;
}

