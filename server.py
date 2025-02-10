from flask import Flask, request, jsonify
from flask_cors import CORS
import os
from openai import OpenAI

# 初始化 OpenAI 客户端
client = OpenAI(
    api_key=os.getenv('DEEPSEEK_API_KEY'),  # 替换自己的 API 密钥
    base_url="https://api.deepseek.com",
)
messages = [{"role": "system", "content": "你是一个有趣的人工智能助手。"}]

app = Flask(__name__)
CORS(app)  # 允许跨域请求

@app.route('/')
def index():
    return "Hello World!"

@app.route('/chat', methods=['POST'])
def chat():
    user_message = request.json.get('message')
    messages.append({"role": "user", "content": user_message})
    print(messages)
    # # 调用 DeepSeek API
    # headers = {
    #     "Authorization": f"Bearer {DEEPSEEK_API_KEY}",
    #     "Content-Type": "application/json"
    # }
    # data = {
    #     "model": "deepseek-chat",
    #     "messages": [{"role": "user", "content": user_message}],
    #     "temperature": 0.7
    # }

    try:
        response = client.chat.completions.create(
            model="deepseek-chat",
            messages=messages,
            # max_tokens=1024,  #默认4096
            # response_format={
            #     'type': 'text'
            # },
            # temperature=0.7,
            stream=False,  # 根据传入的参数控制流式输出，默认false
        )
        bot_reply = response.choices[0].message.content
        # 添加用户消息到对话历史
        messages.append({"role": "assistant", "content": bot_reply})
        print(messages)

        return jsonify({"reply": bot_reply})

    except Exception as e:
        return jsonify({"error": str(e)}), 500




if __name__ == '__main__':
    app.run(host='0.0.0.0', port=5000, debug=False)  # 确保手机能访问此地址