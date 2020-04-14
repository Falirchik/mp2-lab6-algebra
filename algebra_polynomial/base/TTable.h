#pragma once

using namespace std;




template <typename Key, typename Val> class AvlTree {//êëàññ òàáëèöà-ÀÂË-äåðåâî
	Key key;										//êëþ÷
	Val value;										//çíà÷åíèå
	int balance;									//áàëàíñ
	AvlTree <Key, Val>* left;						//óêàçàòåëü íàëåâî
	AvlTree <Key, Val>* right;						// -//- íàïðàâî
	bool empty;										//çàïîëíåíû êëþ÷, çíà÷åíèå?
	
public:
		AvlTree() {										//ïóñòîå äåðåâêî
		empty = true;
		left = nullptr;
		right = nullptr;
		balace = 0;
	}

	AvlTree(Key _key, Val _value) {					//ñîçäàíèå êîðíÿ
		empty = false;
		key = _key;
		value = _value;
		left = right = nullptr;
		balance = 0;
	}

	int Add(Key _key, Val _value) {					//äîáàâëåíèå óçëà. Âîçâðàùàåò, èçìåíèëñÿ ëè áàëàíñ
		if (empty) {
			key = _key;
			value = _value;
			empty = false;
			return 0;
		}
		if (_key == key)
			throw "Óæå ñóùåñòâóåò";
		int b = balance;
		if (_key > key) {
			if (right != nullptr) {
				balance += right->Add(_key, _value);
				TurnAround();
			}
			else {
				right = new AvlTree<Key, Val>(_key, _value);
				balance++;
			}
		}
		else {
			if (left != nullptr) {
				balance -= left->Add(_key, _value);
				TurnAround();
			}
			else {
				left = new AvlTree<Key, Val>(_key, _value);
				balance--;
			}
		}
		if (balace != b) {
			return 1;
		}
		else return 0;
	}

	void TurnAround() {											//íîðìàëèçàöèÿ áàëàíñà. Åñëè áàëàíñ íåðàâíîìåðíûé - ðàçâîðà÷èâàåì óçåë òàê, 
		if (balance == 2) {										//÷òîáû êîëè÷åñòâî ïîòîìêîâ ñïðàâà è ñëåâà íå îòëè÷àëîñü áîëüøå, ÷åì íà 1
			if (right->balance >= 0) {
				Key t_key = key;
				Val t_value = value;
				key = right->key;
				value = right->value;
				right->key = t_key;
				right->value = t_value;
				AvlTree<Key, Val>* t_Node = right->right;
				right->right = right->left;
				right->left = left;
				left = right;
				right = t_Node;
				balance = left->balance - 1;
				left->balance = 1 - left->balance;
			}
			else {
				Key t_key = key;
				Val t_value = value;
				key = right->left->key;
				value = right->left->value;
				right->left->key = t_key;
				right->left->value = t_value;
				AvlTree<Key, Val>* t_Node = right->left->right;
				right->left->right = right->left->left;
				right->left->left = left;
				left = right->left;
				right->left = t_Node;
				balance = 0;
				right->balance = (left->balance == -1) ? (1) : (0);
				left->balance = (left->balance == 1) ? (-1) : (0);
			}
		}
		else {
			if (balance == -2) {
				if (left->balance <= 0) {
					Key t_key = key;
					Val t_value = value;
					key = left->key;
					value = left->value;
					left->key = T_key;
					left->value = t_value;
					AvlTree<Key, Val>* t_Node = left->left;
					left->left = left->right;
					left->right = right;
					right = left;
					left = t_Node;
					balance = 1 + right->balance;
					right->balance = -1 - right->balance;
				}
				else {
					Key t_key = key;
					Val t_value = value;
					key = left->right->key;
					value = left->right->value;
					left->right->key = t_key;
					left->right->value = t_value;
					AvlTree<Key, Val>* t_Node = left->right->left;
					left->right->left = left->right->right;
					left->right->right = right;
					right = left->right;
					left->right = t_Node;
					balance = 0;
					left->balance = (right->balance == 1) ? (-1) : (0);
					right->balance = (right->balance == -1) ? (1) : (0);
				}
			}
		}
	}

	typename AvlTree<Key, Val>* SearchNode(Key _key) { //ïîèñê óçëà ïî êëþ÷ó
		AvlTree<Key, Val>* node = this;
		while (true) {
			if (node == nullptr)
				throw "Íå íàéäåí";
			if (node->key == _key) return node;
			if (node->key < _key)	node = node->right;
			else node = node->left;
		}
	}

	int Delete(Key _key, AvlTree < Key, Val)* parent = nullptr){	//óäàëåíèå óçëà. Ïåðåìåùåíèå ïî äåðåâó ïî êëþ÷ó. Ïðè ïðîõîæäåíèè ìåíÿåì áàëàíñ//ïîêà íå äîøëè äî íóæíîãî óçëà, ïåðåìåùàåì, ïîêà îáà ïîòîìêà íå nullptr

	int b = balance;
	if (key == _key) {
		if (right == nullptr && left == nullptr) {
			if (parent->left->key == this->key) {
				parent->left = nullptr
			}
			else {
				parent->right = nullptr;
			}
			return 1;
		}
		else {
			if (balance >= 0) {
				if (right != nullptr) {
					AvlTree<Key, Val>* t_Node = right;
					while (t_Node->left != nullptr) {
						t_Node = t_Node->left;
					}
					Key t_key = key;
					Val t_value = value;
					key = t_Node->key;
					value = t_Node->value;
					t_Node->key - t_key;
					t_Node->value = t_value;
					balance -= right->Remove(_key, this);
				}
			}
			else {												//ÊÐÀÑÍÈò!
				if (left != nullptr) {
					AvlTree<Key, Val>*t_Node = left;
					while (t_Node->right != nullptr) {
						t_Node = t_Node->right;
					}
					Key t_key = key;
					Val t_value = value;
					key = t_Node->key;
					value = t_Node->value;
					t_Node->key - t_key;
					t_Node->value = t_value;
					balance += left->Delete(_key, this);
				}
			}
		}
	}
	else {
		if (_key > key) {
			if (right != nullptr) {
				balance -= right->Delete(_key, this);
				TurnAround();
			}
			else {
				throw "Íå íàéäåí";
			}
		}
		else {
			if (left != nullptr) {
				balance += left->Delete(_key, this);
				TurnAround();
			}
			else {
				throw "Íå íàéäåí";
			}
		}
	}
	if (balance != b) {
		return (balance == 0) ? (1) : (0);
	}
	else return 0;
	} 

	void Print(AvlTree <Key, Val>* _tree, int level) {		//âûâîä äåðåâà
		if (_tree) {
			Print(_tree->left, level + 1);
			for (int i = 0; i < level; i++)
				cout << "   ";
			cout << _tree->key << endl;
			Print(p->right, level + 1);
		}
	}

	~AvlTree(){}			//äåñòðóêòîð

};  //È ÒÓÒ ÒÎÆÅ!!! ÷òî òåáå íà êîíöå êîììåíòàðèÿ íå íðàâèòñÿ? 
