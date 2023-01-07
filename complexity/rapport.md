# Rapport Devoir Maison Complexity

**Etudiant**: ELHAMER Yacine
**Matricule**: 191938044918

## La recherche des elements

### 1. La recherche d'une valeur dans un tableau non-triees:

#### 1.a. La fonction rechElets\_TabNonTries:
```
Fonction rechElets_TabNonTries(E/ arr: ^entier, E/ len: entier, E/ x: entier): Boolean
Debut
	Var i: entier;
	
	i <- 0;	// 1 u
	tantque(i < len && arr[i] != x) faire	// 2 u	
		i <- i + 1;	// 2 u
	fait;

	retourner (i < len && arr[i] == x); // 2 u
Fin
```

#### 1.b. Calcule de complexity theorique:
- Pire cas: L'element se trouve dans le dernier indice est donc la complexite est: 1 + (2 + 2) \* N - 2 + 2 = 4N + 1 donc elle est d'ordre O(N)
- Meilleur cas: L'element se trouve dans le premier indice est donc la complexite deviendra: 1 + 2 + 2 + 2 = 6 donc elle est d'ordre O(1)


###  2. La recherche d'une valeur dans un tableau triees:

#### 2.1. La recherche sequentielle

##### 2.1.a. La fonction rechElets\_TabTries:

```
Fonction rechElets_TabTries(E/ arr: ^entier, E/ len: entier, E/ x: entier): Boolean
Debut
	Var i: entier;

	i <- 0;	// 1 u
	tantque(i < len && arr[i] < x) faire	// 2 u
		i <- i + 1;	// 2  u
	fait;

	retourner (i < len && arr[i] == x);	// 2 u
Fin
```


##### 2.1.b. Calcule de complexity theorique:
- Pire cas: L'element se trouve dans le dernier indice est donc la complexite est: 1 + (2 + 2) \* N - 2 + 2 = 4N + 1 donc elle est d'ordre O(N)
- Meilleur cas: L'element se trouve dans le premier indice est donc la complexite deviendra: 1 + 2 + 2 + 2 = 6 donc elle est d'ordre O(1)


#### 2.2. La recherche dichotomique:

##### 2.2.a. La fonction rechElets\_Dicho:

```
Fonction rechElets_Dicho(E/ arr: entier, E/ len: entier, E/ x: entier): Boolean
Debut
	Var start: entier;
	Var end: entier;
	Var distance: entier;

	start <- 0;	// 1 u
	end <- len-1; // 2 u
	distance <- end-start; // 2 u

	tantque(start < end && arr[start+distance/2] != x) faire // 4 u
		si(arr[start+distance/2] < x) alors	// 3 u
			start = arr[start+distance/2];	// 3 u
		sinon
			end = arr[start+distance/2];	// 3 u
		fsi;
		
		distance = end - start;	// 2 u
	fait;

	retourner (arr[start+distance/2] == x);	// 3 u
Fin
```

##### 2.2.b. Calcule de complexity theorique:
- Meilleur cas: L'elemnt se trouve au position milieu, et donc la complexite est: A(n) = 5 + 4 + 3 = 12, donc elle est d'ordre O(1)
- Pire cas: L'element se trouve au dernier ou premiere indice, et donc la complexite est: A(n) = 4 + (4 + 6 + 2) \* (log N+1) - 8 + 3 = 12 \* log N + 11, et donc la complexite est d'ordre O(log N)


### 3. Tableau:

// Voir implementation

### 4. Graph de variation:

// Voir implementation

### 5. Conclusion:

// Voir implementation


## La recherche du minimum et maximum:

### 1. Approche Naive:

#### 1.a. La fonction MaxetMinA:

```
Procedure MinEtMaxA(E/ arr: entier, E/ len: entier, S/ min: entier, S/ max: entier)
Debut
	Var i: entier;

	min <- arr[0];	// 1u
	max <- arr[0];	// 1u

	i <- 1;	// 1u
	tantque(i < len) faire	// 1 u
		si(min > arr[i]) alors	// 1 u
			min <- arr[i];	// 1 u
		fsi;
		
		si(max < arr[i]) alors	// 1 u
			max <- arr[i];	// 1 u
		fsi;
	fait;
Fin
```

#### 1.b. Calcule de complexity theorique en nombre de comparisons au pire cas:

Au pire cas, les elements d'indice paire sont trie croissement, et les autre dans un ordre decroissant. Donc la complexite sera: A(n) = 3 + (1 + 2) \* N = 3 \* N + 3, donc la complexite sera d'ordre O(N). Et le nombre de comparisons sera: 2 \* N.

### 2. Algorithme plus efficace:

#### 2.a. La fonction MaxetMinB:

```
Procedure MinEtMaxB(E/ arr: entier, E/ len: entier, S/ min: entier, S/ max: entier)
Debut
	Var i: entier;
	Var temp: entier;

	min <- arr[0];	// 1u
	max <- arr[0];	// 1u

	
	i <- 0;	// 1u
	tantque(i < (len & !1)) faire	// 3u
		si(arr[i] > arr[i+1]) alors	// 2u
			temp = arr[i];	// 1u
			arr[i] = arr[i+1];	// 2u
			arr[i+1] = temp;	// 2u
		fsi;

		i = i+ 2;	// 2u
	fait;

	i <- 0;	// 1u
	tantque(i < len) faire	// 1u
		si(i mod 2 == 1) alors	// 2u
			si(max < arr[i]) alors	// 1u
				max <- arr[i];	// 1u
			fsi;
		sinon
			si(min > arr[i]) alors	// 1u
				min <- arr[i];	// 1u
			fsi;
		fsi;
	fait;

	si(max < arr[len-1]) alors	// 2u
		max <- arr[len-1];	// 2u
	fsi;
	
	si(min > arr[len-1]) alors	// 2u
		min <- arr[len-1];	// 2u
	fsi;
Fin
```

#### 2.b. Calcule de complexity theorique en nombre de comparisons:

Au pire cas, les elements d'indice paire sont trie croissement, et les autre dans un ordre decroissant. Donc la complexite sera: A(n) = 3 + (3+2+1+2+2+2) \* n - 9 + 1 + (1+2+2)\*n - 4 + 4 + 4 = 17\*n - 1, donc la complexite sera d'ordre O(N). Et le nombre de comparisons sera: N/2 + N/2 + N/2 + 2 = 3\*N/2 + 2

### 3. Comparison pratique des deux fonctions en utilisant un compteur de comparisons:

// Voir implementation

### 4. Comparison de complexity temporelle:

// Voir implementation


## Produit de deux matrices:

### 1. Le program de multiplication

```
Procedue produit(E/ A: ^^entier, E/ B: ^^entier, S/ C: ^^entier, E/ n: entier, E/ m: entier, E/ p: entier)
Debut
	Var i: entier;
	Var j: entier;
	Var k: entier;
	
	i <- 0;	// 1u
	tantque(i < n) faire	// 1u
		j <- 0;	// 1u
		tantque(j < p) faire	// 1u
			C[i][j] <- 0;	// 1u

			k <- 0;	// 1u
			tantque(k < m) faire	// 1u
				C[i][j] = C[i][j] + A[i][m] * B[m][j];	// 3u
				k <- k + 1;	// 2u
			fait;
			
			j <- j + 1;	// 2u
		fait;
		
		i <- i + 1;	// 2u
	fait;
Fin
```

### 2. Calcule de complexity temporelle theorique:

A(n) = 1 + n \* (1 + p \* (1 + 2 + m \* (1 + 3 + 2) + 2) + 2) = n \* (p \* (6 \* m + 5) + 3) + 1 = 6 \* npm + 5 \* np + 3 \* n + 1, donc la complexite est d'ordre O(N^3)

### 3. Calcule d'espace memoire utilise:

3 matrices et 3 variables donc: n*m + m*p + n*p + 2

### 4. Mesurer le temps d'execution pratique:

// Voir l'implementation

### 5. Graph de variations:

// Voir l'implementation

### 6. Comparisons entre la complexity theorique et experimentale:

// Voir l'implementation


## Recherche d'une matrice:

### 1.a. La fonction SousMat1:

```
Fonction SousMat1(E/ A: ^^entier, B: ^^entier, E/ n: entier, E/ m: entier, E/ x: entier, E/ z: entier): Boolean
Debut
	Var i: entier;
	Var j: entier;
	Var u: entier;
	Var v: entier;
	Var flag: Boolean;

	i <- 0;	// 1u
	tantque(i < n-x) faire	// 2u
		j <- 0;	// 1u
		tantque(j < m-z) faire // 2u
			u <- 0;	// 1u
			flag <- Faux;	// 1u
			tantque(u < x && flag == Faux) faire	// 2u
				v <- 0;	// 1u
				tantque(v < z && flag == Faux) faire	// 2u
					si(A[i+u][j+v] != B[i+u][j+v]) alors	//5u
						flag == Vrai;	// 1u
					fsi;
				fait;
			fait;
			
			si(flag == Faux) alors	// 1u
				retourner flag;	// 1u
			fsi;

	fait;
Fin
```

### 1.b. Complexite temporelle theorique:

A(n) = 1 + (n-x) (2 + 1 + (m-z) (2 + 1 + 1 + x (2 + 1 + z (2 + 5 + 1)))) = O(N^4)

### 2.a. La fonction SousMat2:

```
Fonction SousMat2(E/ A: ^^entier, B: ^^entier, E/ n: entier, E/ m: entier, E/ x: entier, E/ z: entier): Boolean
Debut
	Var i: entier;
	Var j: entier;
	Var u: entier;
	Var v: entier;
	Var flag: Boolean;

	i <- 0;	// 1u
	tantque(i < n-x) faire	// 2u
		j <- 0;	// 1u
		flag <- Faux;
		tantque(j < m-z && flag == Faux) faire // 4u
			u <- 0;	// 1u
			flag <- Faux;	// 1u
			tantque(u < x && flag == Faux) faire	// 2u
				v <- 0;	// 1u
				tantque(v < z && flag == Faux) faire	// 2u
					si(A[i+u][j+v] != B[i+u][j+v]) alors	//5u
						flag == Vrai;	// 1u
					fsi;
				fait;
			fait;
			
			si(flag == Faux) alors	// 1u
				retourner flag;	// 1u
			fsi;

	fait;
Fin
```

### 2.b. Complexite temporelle theorique

A(n) = 1 + (n-x) (2 + 1 + (m-z)/2 (2 + 1 + 1 + x (2 + 1 + z (2 + 5 + 1)))) = O(N^4)
