#include <stack>
#include <queue>
#include <iostream>

using namespace std;

struct TreeNode {
    double data; // ключ/данные
    TreeNode *left; // указатель на левого потомка
    TreeNode *right; // указатель на правого потомка
};

void FreeTree(TreeNode* root)
{
	if (!root) return;
	FreeTree(root->left);
	FreeTree(root->right);
	delete root;
	return;
}

void add(double value, TreeNode *& relative_node) {
    if (!relative_node) { // Выполняется, если она NULL, т.е. её не существует
        relative_node = new TreeNode;
        relative_node->data = value;
        relative_node->left = nullptr;
        relative_node->right = nullptr;
        return;
    } else
        if (value < relative_node->data) {
            add(value, relative_node->left);
        } else {
            add(value, relative_node->right);
        }
}

TreeNode* del_elem(int value, TreeNode*& root) {
	if (!root)
		return root;

	if (value == root->data) {
		TreeNode* temp;
		if (!root->right)
			temp = root->left;
		else {
			TreeNode* ptr = root->right;
			if (!ptr->left) {
				ptr->left = root->left;
				temp = ptr;
			}
			else {
				TreeNode* pmin = ptr->left;
				while (pmin->left) {
					ptr = pmin;
					pmin = ptr->left;
				}
				ptr->left = pmin->right;
				pmin->left = root->left;
				pmin->right = root->right;
				temp = pmin;
			}
		}
		delete root;
		return temp;
	}
	else if (value < root->data)
		root->left = del_elem(value, root->left);
	else
		root->right = del_elem(value, root->right);
	return root;
}

void rotate_tree_left(TreeNode *&root) { // Поворот дерева влево
    TreeNode* temp = root->right; 
    root->right = temp->left;
    temp->left = root;
    root = temp;
}

void rotate_tree_right(TreeNode *&root) { // Поворот дерева вправо
    TreeNode* temp = root->left;
    root->left = temp->right;
    temp->right = root;
    root = temp;
}

void levelOrderPrint(TreeNode *root) { // Обход в ширину
    if (!root) {
       return;
    }
    queue<TreeNode *> q; // Создаем очередь
    q.push(root); // Вставляем корень в очередь

    while (!q.empty()) { // пока очередь не пуста
        TreeNode* temp = q.front(); // Берем первый элемент в очереди
        q.pop();  // Удаляем первый элемент в очереди
        cout << temp->data << " "; // Печатаем значение первого элемента в очереди

        if (temp->left)
            q.push(temp->left);  // Вставляем  в очередь левого потомка

        if (temp->right)
            q.push(temp->right);  // Вставляем  в очередь правого потомка
   }
}


void preorderPrint(TreeNode *parent) { // Прямой обход в глубину
    if (!parent) {
       return;
    }
    cout << parent->data << " ";
    preorderPrint(parent->left);   //рекурсивный вызов левого поддерева
    preorderPrint(parent->right);  //рекурсивный вызов правого поддерева
}


void inorderPrint(TreeNode *parent) { // Симметричный обход дерева слева
    if (!parent) {
       return;
    }
    preorderPrint(parent->left);   //рекурсивный вызов левого поддерева
    cout << parent->data << " ";
    preorderPrint(parent->right);  //рекурсивный вызов правого поддерева
}


void postorderPrint(TreeNode *parent) { // Обратный обход дерева
    if (!parent) {
       return;
    }
    preorderPrint(parent->left);   //рекурсивный вызов левого поддерева
    preorderPrint(parent->right);  //рекурсивный вызов правого поддерева
    cout << parent->data << " ";
}

void reverseInorderPrint(TreeNode *parent) { // Симметричный обход дерева справа

    if (!parent) {
       return;
    }
    preorderPrint(parent->right);  //рекурсивный вызов правого поддерева
    cout << parent->data << " ";
    preorderPrint(parent->left);   //рекурсивный вызов левого поддерева

}

void iterativePreorder(TreeNode *root) { // Тот же прямой обход, но через стек
    if (!root) {
       return;
    }
    stack<TreeNode *> s;  // Создаем стек. Принцип стека следующий: последним пришёл, первым вышел!
    s.push(root);  // Вставляем корень в стек
    /* Извлекаем из стека один за другим все элементы.
       Для каждого извлеченного делаем следующее
       1) печатаем его
       2) вставляем в стек правого! потомка
       3) вставляем в стек левого! потомка */
    while (!s.empty())
    {
        // Извлекаем вершину стека и печатаем
        TreeNode *temp = s.top();
        s.pop();
        cout << temp->data << " ";

        if (temp->right)
            s.push(temp->right); // Вставляем в стек правого потомка
        if (temp->left)
            s.push(temp->left);  // Вставляем в стек левого потомка
    }
}
int main() {
    TreeNode *root = new TreeNode;
    root->data = 6;
    add(8, root);
    add(4, root);
    add(2, root);
    add(4, root);
    add(7, root);
    add(10, root);
    add(9, root);
    add(15, root);
    add(5, root);
    add(12, root);
    add(6, root);
    add(1, root);
                                       // 6
                        //         4            8
                        //      2    4       7     10
                        //    1        5   6     9   15
                        //                          12

    // levelOrderPrint(root);
    // cout << endl;
    del_elem(10, root);
    preorderPrint(root);
    cout << endl;

    // inorderPrint(root);
    // cout << endl;

    // postorderPrint(root);
    // cout << endl;

    // reverseInorderPrint(root);
    // cout << endl;

    rotate_tree_left(root);
    preorderPrint(root);
    cout << endl;
    return 0;
}