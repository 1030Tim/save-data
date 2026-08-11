import re
from re import sample
role = re.compile(r'\d\d\d')
result = role.search("abc123xyz")
print(str(result.group()))