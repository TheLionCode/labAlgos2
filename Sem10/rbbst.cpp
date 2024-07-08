#include <iostream>
using namespace std;

/*
Se emplea struct en vez de class para ejecutar las funciones de forma publica por defecto.
Mayor explicacion en cada punto del codigo.
Hay un error identificado mas abajo en la linea correspondiente.
*/

/*Se crea la estructura del Nodo con su respectiva llave, guardando su indice de la lista y el color se emplea como un valor booleano (Es negro? Si/No).*/
struct node {
    int key;
    int index;
    bool black;
    node *left, *right, *parent;
};

/*Funcion que crea un nuevo nodo, por defecto los nodos son negros*/
node* newNode(int key, int index, bool black = false)
{
    node* temp = new node;
    temp->key = key;
    temp->index = index;
    temp->black = black;
    temp->left = temp->right = temp->parent = NULL;
    return temp;
}

//Se alterna el arbol izquierdo
void leftRotate(node*& root, node* x)
{
    node* y = x->right;
    x->right = y->left;
    if (y->left != NULL)
        y->left->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->left)
        x->parent->left = y;
    else
        x->parent->right = y;
    y->left = x;
    x->parent = y;
}

//Se alterna el arbol derecho
void rightRotate(node*& root, node* x)
{
    node* y = x->left;
    x->left = y->right;
    if (y->right != NULL)
        y->right->parent = x;
    y->parent = x->parent;
    if (x->parent == NULL)
        root = y;
    else if (x == x->parent->right)
        x->parent->right = y;
    else
        x->parent->left = y;
    y->right = x;
    x->parent = y;
}

//Funcion que arregla los errores de la insercion que infrigen las normas del arbol rojo y negro
void fixInsert(node*& root, node* k)
{
    node* u;
    while (k->parent != NULL && !k->parent->black)
    {
        if (k->parent == k->parent->parent->right)
        {
            u = k->parent->parent->left;
            if (u != NULL && !u->black)
            {
                u->black = k->parent->black = true;
                k->parent->parent->black = false;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->left)
                {
                    k = k->parent;
                    rightRotate(root, k);
                }
                k->parent->black = true;
                k->parent->parent->black = false;
                leftRotate(root, k->parent->parent);
            }
        }
        else
        {
            u = k->parent->parent->right;

            if (u != NULL && !u->black)
            {
                u->black = k->parent->black = true;
                k->parent->parent->black = false;
                k = k->parent->parent;
            }
            else
            {
                if (k == k->parent->right)
                {
                    k = k->parent;
                    leftRotate(root, k);
                }
                k->parent->black = true;
                k->parent->parent->black = false;
                rightRotate(root, k->parent->parent);
            }
        }
        if (k == root)
            break;
    }
    root->black = true;
}

//funcion que inserta un nuevo nodo y llama a la funcion que corrige el arbol
//Error que indica que las variables "x" y "y" estan declaradas fuera del scope, probablemente al solucionar este error aparezca lo mismo en la funcion fixInsert
node*& insert(node*& root, int key, int index)
{
    node* node = newNode(key, index);
    node* y = NULL;
    node* x = root;

    while (x!= NULL)
    {
        y = x;
        if (node->key < x->key)
            x = x->left;
        else
            x = x->right;
    }

    node->parent = y;
    if (y == NULL)
        root = node;
    else if (node->key < y->key)
        y->left = node;
    else
        y->right = node;

    if (node->parent == NULL)
    {
        node->black = true;
        return root;
    }

    if (node->parent->parent == NULL)
        return root;

    fixInsert(root, node);

    return root;
}

//Funcion que busca un nodo en el arbol
int search(node* root, int key)
{
    if (root == NULL)
        return -1;

    if (root->key == key)
        return root->index;

    if (root->key < key)
        return search(root->right, key);

    return search(root->left, key);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, q;
    cin >> n >> q;

    int firstKey;
    cin >> firstKey;

    struct node* root = NULL;
    root = insert(root, firstKey, 0);

    for(int i = 1; i < n; i++){
        int newKey;
        cin >> newKey;
        insert(root, newKey, i);
    }

    for(int i = 0; i < q; i++){
        int newKey;
        cin >> newKey;
        int result = search(root, newKey);
        cout << result << "\n";
    }

    return 0;
}
