## 程式簡介
程式叫做Almost Union-Find，功能則是來自[UVa11987](https://onlinejudge.org/external/119/11987.pdf)的題目要求，以Disjoint Set的資料結構實作，並做成簡易的CLI程式。

## 程式原理
- Find函式（核心功能）

回傳x的父節點。  
每個正整數集合都有其對應的父節點，其資訊存放在parents裡，而初始值都為-1。  
x為欲知其父節點的集合，如果小於0的話代表本身為父節點，否則繼續遞迴尋找。

![carbon (6)](https://user-images.githubusercontent.com/124888991/218031394-7b29946e-38b4-4876-82cd-250865c55844.png)

- Union函式

回傳將p集合及q集合合併後的新parent。  
合併規則為子節點少的集合合併到子節點多的集合，以parents中負數之絕對值來判斷大小。

![carbon (4)](https://user-images.githubusercontent.com/124888991/218031281-8415f3fe-eb78-4f5d-9558-eb210d33d8ab.png)

- Move函式

回傳將p移動到q集合後的新parent。  
移動規則為p的子節點中最大的數當成新的父節點，而p變成q的子節點。

![carbon (7)](https://user-images.githubusercontent.com/124888991/218032766-66dbb7bb-5f4c-4e8b-ad1d-208a500e4355.png)

- Sum函式

以pair回傳包含p之集合的元素數量和總和。

![carbon (8)](https://user-images.githubusercontent.com/124888991/218033306-cc749121-a44c-40cc-8938-f6d795757ef2.png)

## 程式演示
- 初始化程式以及指令表
![image](https://user-images.githubusercontent.com/124888991/218033660-146c4782-7584-4518-b226-3a7fb53060ce.png)

- Union指令和Sum指令
![image](https://user-images.githubusercontent.com/124888991/218034672-6aba55c9-baf2-4f5f-9de3-dc17fc6339d9.png)

- Move指令和Sum指令
![image](https://user-images.githubusercontent.com/124888991/218034827-88e1889a-efe7-482a-926f-2574e8f207af.png)

- Quit 指令
![image](https://user-images.githubusercontent.com/124888991/218035660-51ac4b5f-5a01-410a-a229-291c2a9e20f4.png)
