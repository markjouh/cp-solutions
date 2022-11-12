# Solving a problem in Python!
 
import math
 
t = int(input())
for _ in range(t):
    p_hp, p_att = map(int, input().split())
    m_hp, m_att = map(int, input().split())
    coins, att_add, hp_add = map(int, input().split())
    
    possible = False;
 
    for i in range(coins + 1):
        possible |= math.ceil(m_hp / (p_att + i * att_add)) <= math.ceil((p_hp + (coins - i) * hp_add) / m_att);
 
    print("YES" if possible else "NO")