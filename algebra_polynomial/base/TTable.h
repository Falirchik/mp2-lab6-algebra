#pragma once

template <typename Key, typename Val> class AvlTree { //класс таблица-АВЛ-дерево

public:
	Key key;
	Val value;
	int balance;
	AvlTree <Key, Val>* left;
	AvlTree <Key, Val>* right;
	bool empty;							//заполнены ключ, значение?
	AvlTree() {
		empty = true;
		left = NULL;
		right = NULL;
		balace = 0;
	}

	AvlTree(Key _key, Val _value) {
		empty = false;
		key = _key;
		value = _value;
		left = right = NULL;
		balance = 0;
	}

	int Add(Key _key, Val _value) {		//добавление узла. Возвращает, изменился ли баланс
		if (empty) {
			key = _key;
			value = _value;
			empty = false;
			return 0;
		}
		if (_key == key)
			throw CString(L"Уже существует");
		int b = balance;
		if (_key > key) {
			if (right != NULL) {
				balance += right->Add(_key, _value);
				TurnAround();
			}
			else {
				right = new AvlTree<Key, Val>(_key, _value);
				balance++;
			}
		}
		else {
			if (left != NULL) {
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

	void TurnAround() {	//нормализация баланса. Если баланс неравномерный - разворачиваем узел так, чтобы количество потомков справа и слева не отличалось больше, чем на 1
		if (balance == 2) {
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

	typename AvlTree<Key, Val>* searchNode(Key _key) { //поиск узла по ключу
		AvlTree<Key, Val>* node = this;
		while (true) {
			if (node == NULL)
				throw CString(L"Не найден");
			if (node->key == _key) return node;
			if (node->key < _key)	node = node->right;
			else node = node->left;
		}
	}


};


