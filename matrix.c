//#define _CRT_SECURE_NO_WARNINGS
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include <stdbool.h>
//#include <ctype.h>
//#include <math.h>
//#include <windows.h>
//
//#define rowStringLen 1000
//#define coedStringLen 100
//
//typedef struct {
//	long numerator;
//	long denominator;
//} Fraction;
//
//void printIntTable(int row, int col, int* coefIntArr);
//int devideRow(int row, int col, char*** coefStringArr, char* inputRow);
//bool isAllDigits(const char* s);
//int checkValidRow(int row, int col, char*** coefStringArr, int targetRow);
//void stringTableToIntTable(int row, int col, char*** coefStringArr, int* coefIntArr);
//void swapRows(int* matrix, int row1, int row2, int col);
//void performRowOperation(int* matrix, int targetRow, int pivotRow, int a, int b, int col);
//void printStairMatrix(int row, int col, int* matrix);
//void intTableToStairIntTable(int row, int col, int* coefIntArr, int* stairIntArr);
//Fraction subtractFractions(Fraction a, Fraction b);
//Fraction addFractions(Fraction a, Fraction b);
//void solute(int row, int col, int* stairIntArr);
//
//int main() {
//	printf("��ӭ����BJ��������������@^3^@\n");
//	// ����
//	int col, row;
//	char*** coefStringArr;
//
//	printf("�������������������");
//	scanf("%d", &col);
//	while (getchar() != '\n'); // ������뻺����
//
//	printf("�������������������");
//	scanf("%d", &row);
//	while (getchar() != '\n'); // ������뻺����
//
//	// ������ά�����ڴ�
//	coefStringArr = (char***)malloc(row * sizeof(char**));
//	for (int i = 0; i < row; i++) {
//		coefStringArr[i] = (char**)malloc(col * sizeof(char*));
//		for (int j = 0; j < col; j++) {
//			coefStringArr[i][j] = (char*)malloc(coedStringLen * sizeof(char));
//		}
//	}
//
//	printf("�����������ϵ��������С���ͷ�����\n");
//	for (int row_i = 0; row_i < row;) {
//		printf("������������%d�У�", row_i + 1);
//		char inputRow[rowStringLen];
//		fgets(inputRow, sizeof(inputRow), stdin);
//		inputRow[strcspn(inputRow, "\n")] = '\0';
//
//		if (devideRow(row_i, col, coefStringArr, inputRow) != 0 ||
//			checkValidRow(row, col, coefStringArr, row_i) != 0) {
//			printf("�����ʽ������ע��ո񣩴������������룬ʾ����\na1 a2 a3 a4�س�\n");
//			continue;
//		}
//		row_i++; // ֻ��������ȷʱ�ŵ����к�
//	}
//
//	// ת��Ϊint����
//	int* coefIntArr = (int*)malloc(row * col * sizeof(int));
//
//	stringTableToIntTable(row, col, coefStringArr, coefIntArr);
//	printIntTable(row, col, coefIntArr);
//
//	// ת��Ϊ�����;���
//	int* stairIntArr = (int*)malloc(row * col * sizeof(int));
//	intTableToStairIntTable(row, col, coefIntArr, stairIntArr);
//
//	// �жϽ��������
//	printf("\n---------------����������������---------------\n");
//	solute(row, col, stairIntArr);
//	printf("\n");
//
//	// �ͷ��ڴ�
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			free(coefStringArr[i][j]);  // �ͷŵ���ά�ַ�����
//		}
//		free(coefStringArr[i]);         // �ͷŵڶ�άָ������
//	}
//	free(coefStringArr);                // �ͷŵ�һάָ��
//	coefStringArr = NULL;              // ��������ָ��
//	Sleep(100);
//	return 0;
//}
////��ӡ����������
//void printIntTable(int row, int col, int* coefIntArr) {
//	for (int i = 0; i < row; i++) {
//		for (int j = 0; j < col; j++) {
//			printf("%d ", *(coefIntArr + i * col + j));//������һά����ת��Ϊ�˶�ά�ľ���
//		}
//		printf("\n");
//	}
//}
//// �������string�ɿո�ָ�����Ϊrow + 1��string
//int devideRow(int row, int col, char*** coefStringArr, char* inputRow) {
//	int spaceCount = 0;
//	for (char* p = inputRow; *p != '\0'; ++p) {
//		if (*p == ' ') spaceCount++;
//	}
//	if (spaceCount != col - 1) return -1;
//
//	int count = 0;
//	char* token = strtok(inputRow, " ");
//	while (token != NULL && count < col) {
//		strncpy(coefStringArr[row][count], token, coedStringLen - 1);
//		coefStringArr[row][count][coedStringLen - 1] = '\0';
//		count++;
//		token = strtok(NULL, " ");
//	}
//	return count != col ? -1 : 0;
//}
//
//// ��У�麯���ĸ��������������ַ����Ƿ�ȫΪ����
//bool isAllDigits(const char* s) {
//	if (*s == '\0') return false;
//	while (*s) {
//		if (!isdigit(*s)) return false;
//		s++;
//	}
//	return true;
//}
//
//// ��У�麯��
//int checkValidRow(int row, int col, char*** coefStringArr, int targetRow) {
//	for (int j = 0; j < col; j++) { // �޸�ѭ��������Ϊj
//		const char* str = coefStringArr[targetRow][j];
//		if (!str || *str == '\0') return -1;
//
//		const char* p = str;
//		bool negative = false;
//
//		if (*p == '-') {
//			negative = true;
//			p++;
//			if (*p == '\0') return -1;
//		}
//
//		int slashCount = 0, dotCount = 0;
//		const char* slashPos = NULL, * dotPos = NULL;
//
//		for (const char* c = p; *c; c++) {
//			if (*c == '/') {
//				slashCount++;
//				slashPos = c;
//			}
//			else if (*c == '.') {
//				dotCount++;
//				dotPos = c;
//			}
//			else if (!isdigit(*c)) {
//				return -1;
//			}
//		}
//
//		if ((slashCount > 1) || (dotCount > 1) || (slashCount && dotCount)) {
//			return -1;
//		}
//
//		if (slashCount == 1) {
//			if (slashPos == p || *(slashPos + 1) == '\0') return -1;
//			char numerator[256], denominator[256];
//			strncpy(numerator, p, slashPos - p);
//			numerator[slashPos - p] = '\0';
//			strcpy(denominator, slashPos + 1);
//
//			// ��ǿ��ĸУ��
//			if (!isAllDigits(numerator) ||
//				!isAllDigits(denominator) ||
//				strcmp(denominator, "0") == 0) {
//				return -1;
//			}
//		}
//		else if (dotCount == 1) {
//			if (dotPos == p || *(dotPos + 1) == '\0') return -1;
//			char intPart[256], fracPart[256];
//			strncpy(intPart, p, dotPos - p);
//			intPart[dotPos - p] = '\0';
//			strcpy(fracPart, dotPos + 1);
//			if (!isAllDigits(intPart) || !isAllDigits(fracPart)) return -1;
//		}
//		else {
//			if (!isAllDigits(p)) return -1;
//		}
//	}
//	return 0;
//}
//
//// �������Լ��
//long computeGCD(long a, long b) {
//	while (b != 0) {
//		long temp = b;
//		b = a % b;
//		a = temp;
//	}
//	return a;
//}
//
//// ����Լ��
//void simplifyFraction(Fraction* frac) {
//	long gcd = computeGCD(labs(frac->numerator), frac->denominator);
//	if (gcd == 0) return;
//	frac->numerator /= gcd;
//	frac->denominator /= gcd;
//	if (frac->denominator < 0) { // ��֤��ĸΪ��
//		frac->numerator *= -1;
//		frac->denominator *= -1;
//	}
//}
//
//// �����ַ���Ϊ�����ṹ
//Fraction parseFraction(const char* str) {
//	Fraction result = { 0, 1 };
//	char* p = (char*)str;
//	int sign = 1;
//
//	// �������
//	if (*p == '-') {
//		sign = -1;
//		p++;
//	}
//
//	// ��������
//	char* slash = strchr(p, '/');
//	char* dot = strchr(p, '.');
//
//	if (slash) {
//		// ������ʽ
//		result.numerator = strtol(p, &slash, 10);
//		result.denominator = strtol(slash + 1, NULL, 10);
//	}
//	else if (dot) {
//		// С����ʽ
//		long intPart = strtol(p, &dot, 10);
//		char* decPart = dot + 1;
//		int decimalPlaces = strlen(decPart);
//		long denominator = 1;
//
//		for (int i = 0; i < decimalPlaces; i++)
//			denominator *= 10;
//
//		result.numerator = intPart * denominator + strtol(decPart, NULL, 10);
//		result.denominator = denominator;
//	}
//	else {
//		// ������ʽ
//		result.numerator = strtol(p, NULL, 10);
//		result.denominator = 1;
//	}
//
//	result.numerator *= sign;
//	simplifyFraction(&result);
//	return result;
//}
//
//// ������С������
//long computeLCM(long a, long b) {
//	return a * (b / computeGCD(a, b));
//}
//
////��string����ת��Ϊint����
//void stringTableToIntTable(int row, int col, char*** coefStringArr, int* coefIntArr) {
//	for (int i = 0; i < row; i++) {
//		long max_denominator = 1;
//		Fraction* fractions = (Fraction*)malloc(col * sizeof(Fraction));
//
//		//��������Ԫ�ز��ҵ�����ĸ
//		for (int j = 0; j < col; j++) {
//			fractions[j] = parseFraction(coefStringArr[i][j]);
//			max_denominator = computeLCM(max_denominator, fractions[j].denominator);
//		}
//
//		// ��������ֵ
//		for (int j = 0; j < col; j++) {
//			long multiplier = max_denominator / fractions[j].denominator;
//			coefIntArr[i * col + j] = (int)(fractions[j].numerator * multiplier);
//		}
//
//		free(fractions);
//	}
//}
//
////�������������
//void swapRows(int* matrix, int row1, int row2, int col) {
//	for (int j = 0; j < col; j++) {
//		int temp = matrix[row1 * col + j];
//		matrix[row1 * col + j] = matrix[row2 * col + j];
//		matrix[row2 * col + j] = temp;
//	}
//}
//
////�жԻ�
//void performRowOperation(int* matrix, int targetRow, int pivotRow, int a, int b, int col) {
//	for (int j = 0; j < col; j++) {
//		int targetVal = matrix[targetRow * col + j];
//		int pivotVal = matrix[pivotRow * col + j];
//		matrix[targetRow * col + j] = a * targetVal - b * pivotVal;
//	}
//}
//
////���߿�����ӡ����
//void printStairMatrix(int row, int col, int* matrix) {
//	int* colWidths = (int*)malloc(col * sizeof(int));
//	for (int j = 0; j < col; j++) {
//		int maxWidth = 0;
//		for (int i = 0; i < row; i++) {
//			char buffer[20];
//			int len = sprintf(buffer, "%d", matrix[i * col + j]);
//			maxWidth = len > maxWidth ? len : maxWidth;
//		}
//		colWidths[j] = maxWidth;
//	}
//
//	int totalWidth = 1;
//	for (int j = 0; j < col; j++) {
//		totalWidth += colWidths[j] + 1;
//	}
//	totalWidth += 1;
//
//	printf("_");
//	for (int i = 0; i < totalWidth - 1; i++) printf(" ");
//	printf("_\n");
//
//	for (int i = 0; i < row; i++) {
//		if (i == row - 1) printf("|_");
//		else printf("| ");
//
//		for (int j = 0; j < col; j++) {
//			int value = matrix[i * col + j];
//			if (j == col - 1 && i == row - 1) {
//				printf("%*d_|", colWidths[j], value);
//			}
//			else {
//				printf("%*d ", colWidths[j], value);
//			}
//		}
//
//		if (i != row - 1) printf("|\n");
//		else printf("\n");
//	}
//	free(colWidths);
//}
//
////int����ת��Ϊ������int����
//void intTableToStairIntTable(int row, int col, int* coefIntArr, int* stairIntArr) {
//	memcpy(stairIntArr, coefIntArr, row * col * sizeof(int));
//
//	printf("���ڿ�ʼת��Ϊ�����;���\n");
//	printStairMatrix(row, col, stairIntArr);
//
//	int currentPivotRow = 0;
//	int currentPivotCol = 0;
//
//	while (currentPivotRow < row && currentPivotCol < col) {
//		int pivotRow = -1;
//		for (int i = currentPivotRow; i < row; i++) {
//			if (stairIntArr[i * col + currentPivotCol] != 0) {
//				pivotRow = i;
//				break;
//			}
//		}
//
//		if (pivotRow == -1) {
//			currentPivotCol++;
//			continue;
//		}
//
//		if (pivotRow != currentPivotRow) {
//			swapRows(stairIntArr, currentPivotRow, pivotRow, col);
//			printf("����r%d��r%d=\n", currentPivotRow + 1, pivotRow + 1);
//			printStairMatrix(row, col, stairIntArr);
//		}
//
//		int pivot = stairIntArr[currentPivotRow * col + currentPivotCol];
//		if (pivot == 0) {
//			currentPivotCol++;
//			continue;
//		}
//
//		char operations[1024] = "";
//		bool hasOperations = false;
//
//		for (int i = currentPivotRow + 1; i < row; i++) {
//			int currentVal = stairIntArr[i * col + currentPivotCol];
//			if (currentVal == 0) continue;
//
//			int a = pivot;
//			int b = currentVal;
//			int gcdVal = computeGCD(abs(a), abs(b));
//			if (gcdVal == 0) gcdVal = 1;
//
//			a /= gcdVal;
//			b /= gcdVal;
//
//			if (b < 0) {
//				a = -a;
//				b = -b;
//			}
//
//			char aPart[20], bPart[20];
//			if (a == 1) sprintf(aPart, "r%d", i + 1);
//			else if (a == -1) sprintf(aPart, "-r%d", i + 1);
//			else sprintf(aPart, "%dr%d", a, i + 1);
//
//			if (b == 1) sprintf(bPart, "r%d", currentPivotRow + 1);
//			else if (b == -1) sprintf(bPart, "-r%d", currentPivotRow + 1);
//			else sprintf(bPart, "%dr%d", b, currentPivotRow + 1);
//
//			char op[100];
//			if (operations[0]) sprintf(op, ", %s - %s", aPart, bPart);
//			else sprintf(op, "=%s - %s", aPart, bPart);
//			strcat(operations, op);
//
//			performRowOperation(stairIntArr, i, currentPivotRow, a, b, col);
//			hasOperations = true;
//		}
//
//		if (hasOperations) {
//			printf("%s=\n", operations);
//			printStairMatrix(row, col, stairIntArr);
//		}
//
//		currentPivotRow++;
//		currentPivotCol++;
//	}
//
//	printf("�ѳɹ�ת��Ϊ�����;���\n");
//}
//
////�����Ӽ���
//Fraction subtractFractions(Fraction a, Fraction b) {
//	Fraction result = {
//		a.numerator * b.denominator - b.numerator * a.denominator,
//		a.denominator * b.denominator
//	};
//	simplifyFraction(&result);
//	return result;
//}
//Fraction addFractions(Fraction a, Fraction b) {
//	Fraction result = {
//		a.numerator * b.denominator + b.numerator * a.denominator,
//		a.denominator * b.denominator
//	};
//	simplifyFraction(&result);
//	return result;
//}
//
////�ⷽ�̲�������
//void solute(int row, int col, int* stairIntArr) {
//	// ����Ƿ����ì�ܷ��̣�0x1 + ... +0xn = c��c��0��
//	for (int i = 0; i < row; ++i) {
//		int allZeroCoeff = 1;
//		for (int j = 0; j < col - 1; ++j) {
//			if (stairIntArr[i * col + j] != 0) {
//				allZeroCoeff = 0;
//				break;
//			}
//		}
//		if (allZeroCoeff && stairIntArr[i * col + col - 1] != 0) {
//			printf("�޽�\n");
//			return;
//		}
//	}
//
//	// ����ϵ���������r
//	int r = 0;
//	for (int i = 0; i < row; ++i) {
//		for (int j = 0; j < col - 1; ++j) {
//			if (stairIntArr[i * col + j] != 0) {
//				r++;
//				break;
//			}
//		}
//	}
//
//	if (r == col - 1) { // Ψһ��
//		Fraction* solutions = (Fraction*)malloc((col - 1) * sizeof(Fraction));
//		for (int i = 0; i < col - 1; ++i) {
//			solutions[i].numerator = 0;
//			solutions[i].denominator = 1;
//		}
//
//		// �����һ�п�ʼ�ش�
//		for (int i = row - 1; i >= 0; --i) {
//			int pivotCol = -1;
//			for (int j = 0; j < col - 1; ++j) {
//				if (stairIntArr[i * col + j] != 0) {
//					pivotCol = j;
//					break;
//				}
//			}
//			if (pivotCol == -1) continue;
//
//			// �����ұߵĺ�
//			Fraction sum = { 0, 1 };
//			for (int j = pivotCol + 1; j < col - 1; ++j) {
//				int coeff = stairIntArr[i * col + j];
//				if (coeff == 0) continue;
//
//				Fraction term = { coeff * solutions[j].numerator, solutions[j].denominator };
//				sum = addFractions(sum, term);
//			}
//
//			// ���㵱ǰ����ֵ
//			Fraction rhs = { stairIntArr[i * col + col - 1], 1 };
//			Fraction numerator = subtractFractions(rhs, sum);
//			int coeff = stairIntArr[i * col + pivotCol];
//			solutions[pivotCol].numerator = numerator.numerator;
//			solutions[pivotCol].denominator = numerator.denominator * coeff;
//			simplifyFraction(&solutions[pivotCol]);
//		}
//
//		// ������
//		printf("Ψһ��\n[");
//		for (int i = 0; i < col - 1; ++i) {
//			if (i > 0) printf(",");
//			if (solutions[i].denominator == 1)
//				printf("%ld", solutions[i].numerator);
//			else
//				printf("%ld/%ld", solutions[i].numerator, solutions[i].denominator);
//		}
//		printf("]\n");
//		free(solutions);
//	}
//	else { // ��С�ڱ�������������
//		printf("������\n");
//	}
//}
