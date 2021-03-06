//請助教下載GitHub版本評分

// 10727104_王子威 10727119_吳恩賜 
# include<iostream>
# include<cstring>
# include<stdlib.h>
# include<new>
# include<fstream>
# include<vector> 
# include<cmath>

using namespace std;


class Tree23 {


	typedef struct Data {
		int Num_Of_Graduates ; // 畢業人數
		int ID ; // 序號
	} Data ;
/*	
	typedef struct slotT {
		vector<int> rSet;
		string key;		
	}	slotType;
	
	typedef struct nT {
		slotType data[KEY_NUM];
		struct nT *link[PTR_NUM];
		struct nT *parent;
	} nodeType;
	
	typedef struct pointT {
		nodeType *pnode;
		int pidx;
	} pointType;
	
	typedef struct bT {
		slotType slot;
		nodeType *link;
	} blockType;
*/	
	vector<Data> tree ;

	
private:

	string File_Name ;
	string File_Num ;
	
public:
	
	bool Read_File( string & File_Name ) { 
	
		cout << endl << "Input a file number:" ;
		cin >> File_Num ;  
	
		FILE *InFile = NULL;
		File_Name = "input" + File_Num + ".txt" ;
		InFile = fopen( File_Name.c_str(), "r" ) ;
		
		if ( InFile == NULL )
			cout << endl << File_Name << " does not exist!" << endl ;
			
		else {
			
			tree.clear() ; // 確保清空 
			
			char ch = '\0' ;
			for ( int i = 0 ; i < 3 ; i++ ) {
				for ( ch = '\0'; ch != '\n' ; ch = getc(InFile) ) ;
			}
			
			ch = getc(InFile);
			
			int number = 1 ; // 紀錄用
			 
			while ( ch != EOF ) {
				
				Data temp ;
				string Num = "" ;  
				int num = 0 ;
				
				while ( ch != '\n' ) {
					
					if ( num == 8 )  
						Num = Num + ch ;
					
					if ( ch == '\t' )
						num++ ;
						
					ch = getc(InFile) ;
					
				}
				
				temp.Num_Of_Graduates = atoi( Num.c_str() ) ;
				temp.ID = number ; 
				
				tree.push_back( temp ) ;
				
				number++ ;
				
				if ( ch == '\n' )
					ch = getc(InFile) ;
					
			}
		
			fclose( InFile ) ;
			return true ;
		} 
		
		File_Num = "" ;
		
		return false ;
	}
/*
	vector<int>search23() {
		stack<pointType> aPath;
		vector<int> ridS;
		
		searchPath( sKey, aPath);
		if (!aPath.empty()) {
			pointType curP = aPath.top();
			
			if(!sKey.compare(curP.pnode->data[curP.pidx].key))
				ridS = curP.pnode->data[curP.pidx].rSet;
		}
		
		return rids;
		
	}
	
	void searchPath() {
		pointType oneP;
		int pos ;
		
		while ( cur!= NULL ) {
			oneP.pnode = cur ;
				for( pos = 0 ; pos < KEY_NUM ; pos++ )
					if( ( !cur->data[pos].rSet.size() ) || 
						( ( name.compare( cur->data[pos].key ) ) < 0 ) )
						break;
					else if ( !name.compare( cur->data[pos].key ) ) {
						oneP.pidx = pos;
						path.push(oneP);
						return;
					}
		
			oneP.pidx = pos;
			path.push(oneP);
			cur = cur->link[pos]; 
		} 
	}
	
	void Insert23tree() {
		slotType newSlot ;
		newSlot.rSet.push_back(newRid) ;
		newSlot.key = newKey;
		if( root = NULL )
			root = createNode( NULL, NULL, NULL, newSlot );
		else {
			stack<pointType> aPath;
			pointType curP;
			blockType blockUp;
			
			searchPath( root, newKey, aPath ) ;
			if (!aPath.empty()) {
				curP = aPath.top();
				if ((curP.pnode->data[curP.pidx].rSet.size()) &&
					(!newKey.compare(curP.pnode->data[curP.pidx].key)))
					curP.pnode->data[curP.pidx].rSet.push_back(newRid);
				else if (!curP.pnode->data[KEY_NUM - 1].rSet.size())
					insertLeaf(newSlot, curP) ;
				else {
					splitLeaf(newSlot, curP, blockUp) ;
					if (curP.pnode->parent == NULL)
						root = creatRoot(curP.pnode, blockUp.link, blockUp.slot);
					else
					do {
						aPath.pop();
						curP = aPath.top();
						if(!curP.pnode->data[KEY_NUM - 1].rSet.size()) {
							insertNonleaf(blockUp, curP);
							break;
						}
						else{
							splitNonleaf(curP, blockUp);
							if(curP.pnode->parent == NULL) {
								root = createRoot( curP.pnode, blockUp.link, blockUp.slot) ;
								break;
							}
						}
					}while(true);
				} 
			}
		}
	}
	
	nodeType *createNode() {
		nodeType *newNode = NULL ;
		
		try {
			newNode = new nodeType ;
			newNode->data[0].rSet = newS.rSet;
			newNode->data[1].rSet.clear();
			newNode->data[0].key = newSkey;
			newNode->data[1].key = "" '
			newNode->parent = pNode;
			newNode->link[0] = left;
			newNode->link[1] = right;
			newNode->link[2] = NULL;			
		}
		
		
		catch( std::bad_alloc& ba) {
			std::cerr << endl << "bad_alloc caught:" << ba.what() <<endl ;
		}
		
		retrun newNode;
	}
	
*/
} ; 

class AVLTree {
	
	typedef struct Data {
		int Num_Of_Graduates ; // 畢業人數
		int ID ; // 序號
	} Data ;
	
	typedef struct slotT {
		vector<int> rSet;
		string key;		
	}	slotType;
	
	vector<Data> tree ;
	
private:

	string File_Name ;
	string File_Num ;
	
public:
	
	bool Read_File( string & File_Name ) { 
	
		cout << endl << "Input a file number: " ;
		cin >> File_Num;  
	
		FILE *InFile = NULL;
		File_Name = "input" + File_Num + ".txt" ;
		InFile = fopen( File_Name.c_str(), "r" ) ;
		
		if ( InFile == NULL )
			cout << endl << File_Name << " does not exist!" << endl ;
			
		else {
			
			tree.clear() ; // 確保清空
			
			char ch = '\0' ;
			for ( int i = 0 ; i < 3 ; i++ ) {
				for ( ch = '\0'; ch != '\n' ; ch = getc(InFile) ) ;
			}
			
			ch = getc(InFile) ; // 讀換行 
			
			int number = 1 ; // 紀錄用
			 
			while ( ch != EOF ) {
				
				Data temp ;
				string Num = "" ;  
				int num = 0 ;
				while ( ch != '\n' ) {
					
					if ( num == 8 )  
						Num = Num + ch ;
					
					if ( ch == '\t' )
						num++ ;
						
					ch = getc(InFile) ;
					
				}
				
				temp.Num_Of_Graduates = atoi( Num.c_str() ) ;
				temp.ID = number ; 
				
				tree.push_back( temp ) ;
				
				number++ ;
				
				if ( ch == '\n' )
					ch = getc(InFile) ;
					
			}
		
			fclose( InFile ) ;
			return true ;
		} 
		
		File_Num = "" ;
		
		return false ;
	}
/*
	void InsertAVLTree( int i, int newKey ) {
		if ( root == NULL )  {
			root = new nodeType();
			root->data.key = newKey;
			root->data.rSet.push_back(i);
			root->right = root->left = NULL;
		} 
		else {
			slotType newSlow;
			newSlot.key = newKey;
			newSlot.rSet.push_back(i);
			root = CreateNode( root, newSlot );
		}
	}
	
	nodeType* CreateNode( nodeType *walk, slotType slot ) {
		
		if ( walk == NULL ) {
			walk = new nodeType();
			walk->data.key = slot.key;
			walk->data.rSet = slot.rSet ;
			walk->right = walk->left = NULL ;
			return walk ;
		}
		else if ( walk->data.key > slot.key ) {
			walk->left = CreateNode( walk->left, slot ) ;
		}
		else if ( walk->data.key == slot.key ) {
			walk->data.rSet.push_back( slot.rSet[0] ) ;
		}
		esle if ( walk->data.key < slot.key ) {
			walk->right = CreateNode( walk->right, slot ) ;
		}
		
		if ( CheckRotate( walk ) ) {
			walk = Rotate( walk ) ;
		}
		
		return walk ;
	} 
	
	bool CheckRotate( nodeType *walk) {
		if ( GetHeight( walk->left ) - GetHeight( walk->right ) > 1 ||
		     GetHeight( walk->left ) - GetHeight( walk->right ) < -1 ) {
			return true ;
		}
		else
			retrun false ;
	}
	
	nodeType* Rotate( nodeType *walk) {
		nodeType *temp ;
		if ( GetHeight( walk->left ) - GetHeight( walk->right ) > 1 ) {
			temp = walk->left;
			if ( GetHeight( temp->left ) - GetHeight( temp->right ) >= 0 )
				walk = RotateLL( walk ) ;
			else
				walk = RotateLR( walk ) ;
		}
		
		else if ( GetHeight( walk->left ) - GetHeight( walk->right ) < -1 ) {
			temp = walk->right;
			if ( GetHeight( temp->left ) - GetHeight( temp->right ) <= 0 ) 
				walk = RotateRR( walk ) ;
			else
				walk = RotateRL( walk ) ;
		}
		
		return walk
	}
	
	nodeType RotateLL( nodeType x ) {
		nodeType y = x->left ;
		x->left = y->right ;
		y->right = x;
		return y ;
	}
	
	nodeType RotatRR( nodeType x ) {
		nodeType y = x->right ;
		x->right = y->left ;
		y->left = x;
		return y ;
	}
	
	nodeType RotateLR( nodeType x ) {
		x->left = RotatRR( x->left ) ;
		return RotateLL(x) ;
	}	
		
	nodeType RotateRL( nodeType x ) {
		x->right = RotatLL( x->right ) ;
		return RotateRR(x) ;
	}	
*/
} ; 


int main() {
	
	int command = -1 ; 
	Tree23 Tree_23 ;
	AVLTree AVL_Tree ;
	string FileNum = "" ;
	
	while ( command != 0 ) {
		
		cout << endl << "****  Heap Construction  ****";
		cout << endl << "*  0. 離開                  *";
		cout << endl << "*  1. Build a 2-3 Tree      *";
		cout << endl << "*  2. Build a AVL Tree      *";
		cout << endl << "*****************************";
		cout << endl << "Input a command(0, 1, 2): "  ;
		cin >> command ;
			
		if ( command == 0 )
			cout << endl << "Bye~Bye~" << endl ;
			
		else if ( command == 1 ) { 
		
			if ( Tree_23.Read_File( FileNum ) ) 
				;
				// 23_Tree.Insert23tree() ;
		}
		
		else if ( command == 2 ) {
			
			if ( AVL_Tree.Read_File( FileNum ) ) 
				;
				// AVL_Tree.InsertAVLTree() ;
		}
	}
	
}
