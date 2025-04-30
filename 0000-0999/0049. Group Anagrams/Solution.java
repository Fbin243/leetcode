import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

public class Solution {
	public List<List<String>> groupAnagrams(String[] strs) {
		Map<String, List<String>> ans = new HashMap<>();
		for (String s : strs) {
			int[] freq = new int[26];
			for (char c : s.toCharArray()) {
				freq[c - 'a']++;
			}

			StringBuilder keyBuilder = new StringBuilder();
			for (int count : freq) {
				keyBuilder.append(count).append("#");
			}
			String key = keyBuilder.toString();

			if (!ans.containsKey(key)) {
				ans.put(key, new ArrayList<>());
			}
			ans.get(key).add(s);
		}

		return new ArrayList<>(ans.values());
	}
}
