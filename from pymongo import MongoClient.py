import pymongo
client = pymongo.MongoClient("mongodb://localhost:27017/")
db = client["company"]
sales = db["sales"]
print("Connected to MongoDB")
client.close()
print("\nConnection closed")
