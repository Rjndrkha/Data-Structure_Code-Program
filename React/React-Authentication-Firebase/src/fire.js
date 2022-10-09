 import firebase from 'firebase';
 
 var firebaseConfig = {
    apiKey: "AIzaSyAjNKxuexll2z8OAWFF9qldAeP1VPjCVuw",
    authDomain: "login-react-ab8a0.firebaseapp.com",
    projectId: "login-react-ab8a0",
    storageBucket: "login-react-ab8a0.appspot.com",
    messagingSenderId: "403540874878",
    appId: "1:403540874878:web:6fbf873c65932928acea2f"
  };

  const fire = firebase.initializeApp(firebaseConfig);

  export default fire;