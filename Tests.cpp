import nltk
from nltk.chat.util import Chat, reflections

pairs = [
    # Common Questions and Answers
    [
        r"my name is (.*)",
        ["Hello %1, How are you today?",]
    ],
    [
        r"hi|hey|hello",
        ["Hello", "Hey there",]
    ],
    [
        r"what is your name?",
        ["You can call me Chatbot.",]
    ],
    [
        r"how are you ?",
        ["I'm doing good, thank you!", "I'm fine, thanks for asking.",]
    ],
    [
        r"sorry (.*)",
        ["No problem", "Don't worry",]
    ],
    [
        r"quit",
        ["Bye-bye, take care!", "It was nice talking to you. Goodbye!"]
    ],
    [
        r"What types of clothing do you sell?",
        ["We offer a wide range of clothing, including tops, bottoms, dresses, outerwear, and accessories."]
    ],
    [
        r"Can you show me your latest collection?",
        ["Certainly! Please visit our website [website link] to explore our latest collection."]
    ],
    [
        r"Do you have any discounts or promotions?",
        ["Yes, we frequently have discounts and promotions. Visit our website or check our social media pages for the latest offers."]
    ],
    [
        r"Can you recommend trendy outfits for a specific occasion?",
        ["Of course! If you provide more details about the occasion and your preferences, I can suggest some stylish outfit ideas."]
    ],
    [
        r"What sizes are available for this shirt?",
        ["Our shirts are available in sizes XS to XXL. Please refer to our size chart on the product page for precise measurements."]
    ],
    [
        r"How do I determine my size?",
        ["To find your size, you can refer to our size guide available on our website. It provides instructions on measuring yourself accurately."]
    ],
    [
        r"Can you provide measurements for a specific product?",
        ["Certainly! Please provide the name or product code of the item you're interested in, and I'll provide you with the measurements."]
    ],
    [
        r"How can I place an order?",
        ["You can easily place an order on our website by adding items to your cart and following the checkout process."]
    ],
    [
        r"Do you offer international shipping?",
        ["Yes, we offer international shipping to several countries. During checkout, you can select your country for shipping options."]
    ],
    [
        r"What are the payment options?",
        ["We accept major credit cards, PayPal, and other secure online payment methods. You can choose your preferred option during checkout."]
    ],
    [
        r"Can I track my order?",
        ["Absolutely! Once your order is shipped, we will provide you with a tracking number and a link to track your package."]
    ],
    [
        r"What is your return policy?",
        ["Our return policy allows returns within 30 days of purchase. Please visit our website or contact our customer support for detailed instructions."]
    ],
    [
        r"How can I initiate a return or exchange?",
        ["To initiate a return or exchange, please contact our customer support team with your order details. They will guide you through the process."]
    ],
    [
        r"What if I receive a defective or incorrect item?",
        ["If you receive a defective or incorrect item, please contact our customer support immediately. We will arrange a return or exchange at no additional cost."]
    ],
    [
        r"Where is your nearest store located?",
        ["We have several store locations. Please visit our website's store locator to find the nearest store to your location."]
    ],
    [
        r"What are your store opening and closing hours?",
        ["Our store opening and closing hours may vary by location. Please check our website or contact the specific store for accurate details."]
    ],
    [
        r"Do you have any upcoming events or sales in-store?",
        ["Yes, we frequently organize special events and sales. Keep an eye on our website and social media pages for updates on upcoming events and promotions."]
    ],
    [
        r"How can I contact your customer support?",
        ["You can reach our customer support team by calling our toll-free number or sending an email to [email address]."]
    ],
    [
        r"Can you assist me with a specific issue?",
        ["Of course! Please provide details about your issue, and I'll do my best to assist you or connect you with a customer support representative."]
    ],
]

def chatbot():
    print("Hello! I'm a chatbot. How can I assist you today?")
    chat = Chat(pairs, reflections)
    chat.converse()

if __name__ == "__main__":
    chatbot()
