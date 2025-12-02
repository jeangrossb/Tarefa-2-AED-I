/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* rotateRight(struct ListNode* head, int k) {


    if(head == NULL || head->next == NULL) {
        return head;
    }

    //Percorre até o final da lista
    struct ListNode* ultimo = head;
    int tamanho = 1;

    while(ultimo->next != NULL){
        ultimo = ultimo->next;
        tamanho++;
    }

    // Tira rotações desnecessárias se o tamanho extrapolar
    k = k % tamanho;

    // Se der zero, não precisa mexer em nada
    if(k == 0) {
        return head;
    }

    struct ListNode* auxiliar = head;
    
    // Anda até um antes de onde vai virar a nova cabeça
    for(int i = 0; i < tamanho - k - 1; i++){
        auxiliar = auxiliar->next;
    }

    // A nova cabeça é o próximo depois do auxiliar
    struct ListNode* nova_cabeca = auxiliar->next;

    // Finaliza a lista
    auxiliar->next = NULL;

    ultimo->next = head;

    return nova_cabeca;
}