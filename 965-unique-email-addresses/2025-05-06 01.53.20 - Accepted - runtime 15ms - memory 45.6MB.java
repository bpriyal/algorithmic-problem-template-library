class Solution {
    public int numUniqueEmails(String[] emails) {
        Set<String> uniqueMails = new HashSet<>();

        for (String mailid : emails) {
            String[] splits = mailid.split("@");
            String localName[] = splits[0].split("\\+");
            uniqueMails.add(localName[0].replace(".","") + "@" + splits[1]);
            // System.out.println(localName);
        }
        return uniqueMails.size();
    }
}