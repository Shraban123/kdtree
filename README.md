# Blockchain and Big Data to Transform the Healthcare
Big data refers to massive volume of structured and unstructured data so large that it is difficult to process using traditional database or software techniques. In healthcare, data is being generated continuously, every time we visit our primary care physician or a specialist, every trip to an emergency room (ER) or any surgical procedures that we undergo. In addition, now with the availability of wearables and other IoT devices, the amount of data being generated is multiplying fast. 

Healthcare data are a valuable source of healthcare intelligence. Sharing of healthcare data is one essential step to make healthcare system smarter and improve the quality of healthcare service. Healthcare data, one personal asset of patient, should be owned and controlled by patient, instead of being scattered in different healthcare systems, which prevents data sharing and puts patient privacy at risks. Blockchain is demonstrated in the financial field that trusted, auditable computing is possible using a decentralized network of peers accompanied by a public ledger.

Health information is something hackers look for therefore it is very important to protect this data. Failure to protect patient records can have serious financial and legal consequences and it can impact patient care. Implementing the proper security can be quite expensive, and this could lead to improper security measures in place.

A big challenge for healthcare data systems to become smarter is how to gather, store and analyse personal healthcare data without raising privacy violations.
My motivation behind this blog is to explain the solution using blockchain that would allow different participants in the healthcare to come together and share data which will not only reduce cost but also provide many other benefits, such as, efficiency in care delivery for the patient where multiple providers can share data that they currently have in silos within their own medical records systems.

Blockchain is first used in Bitcoin as an accounting system with a public, secure, and verified ledger, and may be viewed as storage supply chain in which every operation may be verified, accountable and immutable. Such inherent characteristics make it a potential solution for health care data systems that concerns both sharing and patient privacy. 

A solution I have studied used a private blockchain where individual entities such as health care providers, laboratories, hospital, etc. would be nodes in the blockchain, so they can all share data with each other or send information related to a visit made by the individual to one of these providers. The blockchain itself will contain a list of all the health records and data collected throughout a patient’s lifetime along with the type of data and the location where this data is located.  The transactions in the blocks would contain an identifier that is unique to the user, it will also hold an encrypted link to where the health record is actually stored, type of data contained in the health record and a time stamp of when the transaction took place. 

## Advantage of Blockchain over current systems
There are several benefits to the healthcare industry based on the above mentioned solution.
1. Using blockchain will allow patients, healthcare providers, researchers and others to access accurate information in a timely manner. Currently, there are Electronic Medical Records systems that are centralized, or the data is stored in paper files in the physicians’ office. Getting access to this information can take several days if not week. A blockchain solution offers many advantages to healthcare providers, individuals, researchers and others who actively participate in the healthcare industry.  Researchers in healthcare require access to comprehensive medical data in order for them to get a better understanding of diseases, fast track the development of drugs and design treatment plans that are based on a patient’s genetic makeup.
2. A blockchain with its de-centralized nature would provide a diverse set of data by including information about patients from different ethnic backgrounds and from diverse geographical environments. It can collect health data across a patient’s lifetime.
3. Blockchain could provide real-time access to data, this could improve clinical care coordination and vastly improve clinical care in emergency situation. It will allow researchers and those in public health service to rapidly detect conditions that can impact public health.
4. Epidemics can be detected and contained faster. The healthcare provider and patients will have access to the same information and they would be able to engage in a collaborative discussion about the best treatment available based on research and not just intuition.
5. This system will help eliminate healthcare breaches, provide a way for facilitated care coordination that will improve overall health outcomes.

The above conditions are implemented in an app in the research paper[1]. The handling of such a large amount of data is done using two data structures namely K-D tree and R-tree.


<center><img src="picture2.PNG"/><br>Fig 1. Three Tier Solution</center>
<center><img src="picture3.PNG"/><br>Fig 2. Participants in the health care blockchain</center>
<center><img src="picture4.PNG"/><br>Fig 3. Example of a blockchain</center>
In this blog I will explain one of the two data structures which is called KD Tree and in the next blog I will explain R-tree.
## KD TREE
A K-D Tree (also called as K-Dimensional Tree) is a binary search tree where data in each node is a K-Dimensional point in space. In short, it is a space partitioning(details below) data structure for organizing points in a K-Dimensional space.

A non-leaf node in K-D tree divides the space into two parts, called as half-spaces.
Points to the left of this space are represented by the left subtree of that node and points to the right of the space are represented by the right subtree. We will soon be explaining the concept on how the space is divided and tree is formed.

For the sake of simplicity, let us understand a 2-D Tree with an example.
The root would have an x-aligned plane, the root’s children would both have y-aligned planes, the root’s grandchildren would all have x-aligned planes, and the root’s great-grandchildren would all have y-aligned planes and so on.

**Generalization**:

Let us number the planes as 0, 1, 2, …(K – 1). From the above example, it is quite clear that a point (node) at depth D will have A aligned plane where A is calculated as:
A = D mod K

**Determining if a point will lie in the left subtree or in right subtree?**

If the root node is aligned in plane A, then the left subtree will contain all points whose coordinates in that plane are smaller than that of root node. Similarly, the right subtree will contain all points whose coordinates in that plane are greater-equal to that of root node.

**Creation of a 2-D Tree:**

Consider following points in a 2-D plane:

**(3, 6), (17, 15), (13, 15), (6, 12), (9, 1), (2, 7), (10, 19)**
1. Insert (3, 6). Since tree is empty, make it the root node. 
2. Insert (17, 15). Compare it with root node point. Since root node is X-aligned, the X-coordinate value will be compared to determine if it lies in the left subtree or in the right subtree. This point will be Y-aligned. 
3. Insert (13, 15). X-value of this point is greater than X-value of point in root node. So, this will lie in the right subtree of (3, 6). Again compare Y-value of this point with the Y-value of point (17, 15). Since, they are equal, this point will lie in the right subtree of (17, 15). This point will be X-aligned. 
4. Insert (6, 12). X-value of this point is greater than X-value of point in root node. So, this will lie in the right subtree of (3, 6). Again Compare Y-value of this point with the Y-value of point (17, 15). Since, 12 < 15, this point will lie in the left subtree of (17, 15). This point will be X-aligned. 
5. Insert (9, 1). Similarly, this point will lie in the right of (6, 12). 
6. Insert (2, 7). Similarly, this point will lie in the left of (3, 6). 
7. Insert (10, 19). Similarly, this point will lie in the left of (13, 15).

<center><img src="picture5_2.PNG"/><br>Fig 4.</center>

**How is space partitioned?**

All 7 points will be plotted in the X-Y plane as follows:
1. Point (3, 6) will divide the space into two parts: Draw line X = 3.
2. Point (2, 7) will divide the space to the left of line X = 3 into two parts horizontally. Draw line Y = 7 to the left of line X = 3.
3. Point (17, 15) will divide the space to the right of line X = 3 into two parts horizontally. Draw line Y = 15 to the right of line X = 3.
4. Point (6, 12) will divide the space below line Y = 15 and to the right of line X = 3 into two parts. Draw line X = 6 to the right of line X = 3 and below line Y = 15.
5. Point (13, 15) will divide the space below line Y = 15 and to the right of line X = 6 into two parts. Draw line X = 13 to the right of line X = 6 and below line Y = 15.
6. Point (9, 1) will divide the space between lines X = 3, X = 6 and Y = 15 into two parts. Draw line Y = 1 between lines X = 3 and X = 6.
7. Point (10, 19) will divide the space to the right of line X = 3 and above line Y = 15 into two parts. Draw line Y = 19 to the right of line X = 3 and above line Y = 15.

**Division of the space by each of the above insertions**
<center><img src="6.PNG"/><br>Insertion 1.</center>
<center><img src="7.PNG"/><br>Insertion 2.</center>
<center><img src="8.PNG"/><br>Insertion 3.</center>
<center><img src="9.PNG"/><br>Insertion 4.</center>
<center><img src="10.PNG"/><br>Insertion 5.</center>
<center><img src="11.PNG"/><br>Insertion 6.</center>
<center><img src="12.PNG"/><br>Insertion 7.</center>

A link for source code in C++ has been attached
https://github.com/Shraban123/kdtree/tree/master

References:
1. Blockchain and Big Data to Transform the Healthcare by Md Zakirul Alam Bhuiyan, Aliuz Zaman, Tian Wang, Guojun Wang, Hai Tao, Mohammad Mehedi Hassan.
2. Multidimensional Binary Search Trees Used for Associative Searching by Jon Louis Bentley, Stanford University.
3. Healthcare Data Gateways: Found Healthcare Intelligence on Blockchain with Novel Privacy Risk Control by Xiao Yue, Huiju Wang, Dawei Jin, Mingqiang Li, Wei Jiang2.
4. Internet of Things for Smart Healthcare: Technologies, Challenges, and Opportunities by Stephanie B. Baker, Wei Xiang (Senior Member, IEEE), AND Ian Atkinson.
5. Big Data: An Emerging Trend In Future by Sampada Lovalekar, Depart of IT, SIES Graduate School of Technology, Nerul, Navi Mumbai, India.
6. A Survey on Big Data Analytics: Challenges, Open Research Issues and Tools by D. P. Acharjya and Kauser Ahmed P, School of Computing Science and Engineering VIT University Vellore, India 632014
7. Aashish Barnwal from geeksforgeeks.org
