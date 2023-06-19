class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        Arrays.sort(deck);
        int[] perfectDeck = new int[deck.length];

        // int ind =  0;
        int ind = 0;
        for (int i = 0; i < deck.length && ind < deck.length; i += 2, ++ind) {
            // System.out.println(i);
            // System.out.println(i + " " + deck[ind]);
            perfectDeck[i] = deck[ind];
            // System.out.println(perfectDeck.get(i));
        }
        // System.out.println("perfectDeck.get(2)" + perfectDeck.get(2));
        System.out.println(perfectDeck);

        for (int j = 1; j < deck.length && ind < deck.length; j += 2, ++ind) {
            System.out.println(j + " " + deck[ind]);
            perfectDeck[j] = deck[ind];
            // System.out.println(perfectDeck.get(j));
        }
        System.out.println(perfectDeck);
        // System.out.println(perfectDeck.get(2));
        // System.out.println(perfectDeck.size());

        return perfectDeck;
    }
}