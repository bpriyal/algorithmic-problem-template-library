class Solution {
    public double[] calcEquation(List<List<String>> equations, double[] values, List<List<String>> queries) {
        Map<String, List<Pair>> conns = new HashMap();
        int i = 0;
        for (List<String> eq : equations) {
            Pair pn = new Pair(eq.get(1), values[i]);
            if (!conns.containsKey(eq.get(0))) {
                conns.put(eq.get(0), new ArrayList<Pair>(Arrays.asList(pn)));
            } else {
                conns.get(eq.get(0)).add(pn);
                // List<Pair> updatedl = ;
                // conns.replace(eq.get(0), updatedl);
            }

            Pair pd = new Pair(eq.get(0), 1/values[i]);
            if (!conns.containsKey(eq.get(1))) {
                conns.put(eq.get(1), new ArrayList<Pair>(Arrays.asList(pd)));
            } else {
                conns.get(eq.get(1)).add(pd);
                // List<Pair> updatedl = conns.get(eq.get(1)).add(pd);
                // conns.replace(eq.get(1), updatedl);
            }
            ++i;
        }

        double[] result = new double[queries.size()];
        int j = 0;
        for (List<String> q: queries) {
            if (!(conns.containsKey(q.get(0)) && conns.containsKey(q.get(1)))) { result[j++] = -1; continue;}
            result[j++] = dfs (conns, q.get(0), q.get(1));
        }

        return result;
    }
// a/b * b/c * c/d = a/d
    double dfs(Map<String, List<Pair>> conns, String num, String denom) {
        if (num == denom) return 1.0;
        List<Pair> possDenoms = conns.get(num);
        for (Pair p : possDenoms) {
            String d = p.denom;
            if (d.equals(denom)) return p.ans;
        }
        double mult;
        for (Pair p : possDenoms) {
            mult = dfs(conns, p.denom, denom);
            if (mult != -1.0) return p.ans * mult;
        }
        return -1.0;
    }
}

class Pair {
    public final String denom;
    public final double ans;

    public Pair(String d, double val) {
        denom = d;
        ans = val;
    }

    @Override
    public String toString() {
        return (" /" + denom + " = " + ans);
    }
}

// a/b * b/c = a/c

// a - b
// b - c = a - c

