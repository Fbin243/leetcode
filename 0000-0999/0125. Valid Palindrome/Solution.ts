function isPalindrome(s: string): boolean {
	let i = 0, j = s.length - 1;
	while(i < j) {
			while(i < j && !isAlphanumeric(s[i])) i++;
			while(i < j && !isAlphanumeric(s[j])) j--;
			if(s[i].toLowerCase() != s[j].toLowerCase()) return false;
			i++; j--;
	}

	return true;
};

function isAlphanumeric(str: string): boolean {
return /^[a-zA-Z0-9]+$/.test(str);
}