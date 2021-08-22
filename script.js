import { ChatHandler, chat_names } from './ChatHandler.js';

onload = function () {

    // chat list
    const chatlist = document.getElementById('chat-list');

    // button to generate new step
    const add = document.getElementById('generate-step');

    // text to display when new operation is performed
    const text = document.getElementById('temptext');

    const templates = document.getElementsByTagName('template')[0];
    const chat_item = templates.content.querySelector("li");

    const chatHandler = new ChatHandler(chat_item, chatlist);
    
    // this array will hold the id's of the person having message in the chat list 
    let chats = [];

    add.onclick = function () {
        if(Math.random()>0.75 && chats.length > 0){
            let index = Math.floor(Math.random()*chats.length);
            let idToDelete = chats[index];
            chatHandler.deleteMsg(idToDelete);
            text.innerHTML = "Deleted message from "+chat_names[idToDelete] + "<br>" + text.innerHTML;
                chats.splice(index, 1);
        } else{
            let idOfMsg = Math.floor(Math.random()*7);

            // if the chat list doesn't containa a message from the random id generated 
            if(chats.includes(idOfMsg)===false){
                chats.push(idOfMsg);
            }
            chatHandler.newMsg(idOfMsg);
            text.innerHTML = "New message from "+chat_names[idOfMsg] + "<br>" + text.innerHTML;
        }
    };
};
