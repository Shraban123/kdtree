//This program is used for insertion and searching in a K-d tree
//This program is partly inspired by a code snippet by Aashish Barnwal 
#include<bits/stdc++.h> 
using namespace std;

const int k = 2; 

struct Node 
{ 
	int coordinates[k];
	Node *left, *right; 
}; 

struct Node* newNode(int arr[]) 
{ 
	struct Node* temp = new Node; 
    int i;
	for (i=0; i<k; i++) 
	temp->coordinates[i] = arr[i]; 

	temp->right = temp->left = NULL; 
	return temp; 
} 
Node *recursiveInsert(Node *root, int coordinates[], int d) 
{ 
	//Check if tree is empty? 
	if (root == NULL) 
	return newNode(coordinates); 
 
	int cd = d % k; 

	if (coordinates[cd] < (root->coordinates[cd])) 
		root->left = recursiveInsert(root->left, coordinates, d + 1); 
	else
		root->right = recursiveInsert(root->right, coordinates, d + 1); 

	return root; 
} 
 
Node* insertion(Node *root, int coordinates[]) 
{ 
	return recursiveInsert(root, coordinates, 0); 
} 

int arePointsSame(int coordinate1[], int coordinate2[]) 
{
	int i;
	for (i = 0; i < k; ++i) 
		if (coordinate1[i] != coordinate2[i]) 
			return 0; 

	return 1; 
} 

int searchRec(Node* root, int coordinates[], int d) 
{ 
	if (root == NULL)
		return 0; 
	if (arePointsSame(root->coordinates, coordinates)) 
		return 1; 
	int cd = d % k; 

	if (coordinates[cd] < root->coordinates[cd]) 
		return searchRec(root->left, coordinates, d + 1); 

	return searchRec(root->right, coordinates, d + 1); 
} 

int searchNode(Node* root, int coordinates[]) 
{
	return searchRec(root, coordinates, 0); 
} 

// Main----------------------------------------------------
int main() 
{ 
    int no,n,i;
	struct Node *root = NULL; 
	printf("Please enter the number of points: ");
	scanf("%d",&no);
	int points[no][2];
	printf("Please enter the coordinates:\n");
	for( i = 0 ; i < no; i++ )
	{
		scanf("%d",&points[i][0]);
		scanf("%d",&points[i][1]);
	}
	n = sizeof(points)/sizeof(points[0]); 

	for (i=0; i<n; i++) 
	root = insertion(root, points[i]); 

	printf("Please enter 1 to exit\n");
	int exitVar = 1;
	do
	{
		int coordinates[2];
		printf("Please enter the 2-D coordinates to search: ");
		scanf("%d",&coordinates[0]);
		scanf("%d",&coordinates[1]);
		(searchNode(root, coordinates))? printf("Found\n"): printf("Not Found\n");
		printf("Please enter the exit variable: ");
		scanf("%d",&exitVar);
	}while(exitVar!=1);
	

	return 0; 
} 
