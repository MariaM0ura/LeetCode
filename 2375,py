class Solution:
    def smallestNumber(self, pattern: str) -> str:
        result = []
        stack = []
        
        for i in range(len(pattern) + 1):
            stack.append(str(i + 1))  # Adiciona o próximo número disponível
            
            if i == len(pattern) or pattern[i] == 'I':
                while stack:
                    result.append(stack.pop())  # Desempilha na ordem correta
        
        return "".join(result)
