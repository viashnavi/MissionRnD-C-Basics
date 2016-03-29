/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

int lengthOfStr(char *str){
	int i;
	for (i = 0; str[i]; i++);
	return i;
}

int validtionOfDate(char* dob1){
	int y1 = (dob1[9] - '0') + ((dob1[8] - '0') * 10);
	if (dob1[3] == '1' && dob1[4] >'2'){
		return -1;
	}
	else{
		if (dob1[0] >= '3'){
			return -1;
		}
		else if ((y1 % 4 == 0) && (dob1[3] == '0' && dob1[4] == '2')){
			if (dob1[0] == '3'){
				return -1;
			}
		}
		else if ((y1 % 4 != 0) && (dob1[3] == '0' && dob1[4] == '2')){
			if ((dob1[0] == '3') || (dob1[0] == '2' && dob1[1] == '9')){
				return -1;
			}
		}
		else{
			if (dob1[3] == '0'){
				if (dob1[4] == '1' || dob1[4] == '3' || dob1[4] == '5' || dob1[4] == '7' || dob1[4] == '8'){
					if (dob1[0] == '3' && dob1[1] >= '2'){
						return -1;
					}
				}
				else{
					if (dob1[0] == '3' && dob1[1] >= '1'){
						return -1;
					}
				}
			}
			else{
				if (dob1[4] == '1'){
					if (dob1[0] == '3' && dob1[1] >= '1'){
						return -1;
					}
				}
				else{
					if (dob1[0] == '3' && dob1[1] >= '2'){
						return -1;
					}
				}
			}
		}
	}
	return 1;
}

int whoIsOlder(char* dob1, char* dob2,int low,int high){
	int i;
	for (i = low; i < high; i++){
		if (dob1[i] < dob2[i]){
			return 1;
		}
		else if (dob1[i] > dob2[i]){
			return 2;
		}
	}
	return 0;
}

int isOlder(char *dob1, char *dob2) {
	int l1 = lengthOfStr(dob1);
	int l2 = lengthOfStr(dob2);
	
	//validation 1
	if (l1 == 10 && l2 == 10){
		//validation2
		for (int i = 0; i < 10; i++){
			if (i != 2 && i != 5){
				if ((dob1[i] >= '0' && dob1[i] <= '9') && (dob2[i] >= '0' && dob2[i] <= '9')){
					//24-07-2000
					continue;
				}
				return -1;
				
			}
		}
		
		//validation3
		if (validtionOfDate(dob1) == -1 || validtionOfDate(dob2) == -1){
			return -1;
		}
		else{
			//After validation
			int res1 = whoIsOlder(dob1, dob2, 6, 10);
			if (res1 == 0){
				int res2 = whoIsOlder(dob1, dob2, 3, 5);
				if (res2 == 0){
					int res3 = whoIsOlder(dob1, dob2, 0, 2);
					if (res3 == 0){
						return 0;
					}
					return res3;
				}
				return res2;
			}
			return res1;
		}
	}
	else{
		return -1;
	}
	return 0;
}
