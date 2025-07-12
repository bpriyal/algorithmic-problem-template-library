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
        // boolean[] visited = new boolean[conns.ketSet().size()];
        double[] result = new double[queries.size()];
        int j = 0;
        for (List<String> q: queries) {
            Set<String> visited = new HashSet();
            Map<String, List<Pair>> conns1 = new HashMap(conns);
            if (q.get(0) == q.get(1)) {
                result[j++] = 1.0;
                continue;
            }
            if (!(conns1.containsKey(q.get(0)) && conns1.containsKey(q.get(1)))) { 
                result[j++] = -1;
                continue;}
            result[j++] = dfs (conns1, q.get(0), q.get(1), visited);
        }
        return result;
    }

    double dfs(Map<String, List<Pair>> conns1, String num, String denom, Set visited) {
        if (visited.contains(num)) return -1.0;
        if (visited.contains(num)) return -1.0;
        if (num.equals(denom)) return 1.0;
        
        List<Pair> possDenoms = conns1.get(num);
        for (Pair p : possDenoms) {
            String d = p.denom;
            if (d.equals(denom)) {
                conns1.remove(num);
                return p.ans;
            }
        }
        double mult;
        for (Pair p : possDenoms) {
            Set<String> s = new HashSet(visited);
            s.add(num);
            mult = dfs(conns1, p.denom, denom, s);
            if (mult != -1.0) {
                return p.ans * mult;
            }
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

