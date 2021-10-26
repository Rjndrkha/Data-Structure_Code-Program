import DrawerInitiator from '../utils/drawer-initiator';
import UrlParser from '../routes/url-parser';
import routes from '../routes/routes';

class App {
  constructor({ button, drawer, content }) {
    this._button = button;
    this._drawer = drawer;
    this._content = content;

    this._initialAppShell();
  }

  _initialAppShell() {
    DrawerInitiator.init({
      button: this._button,
      drawer: this._drawer,
      content: this._content,
    });
    // kita bisa menginisiasikan komponen lain bila ada
  }

  async renderPage() {
    // let scriptElement = document.querySelector('script[src="https://use.fontawesome.com/b070c8f1df.js"]');

    // if (!scriptElement) {
    //   scriptElement = document.createElement('script');
    //   scriptElement.src = 'https://use.fontawesome.com/b070c8f1df.js';
    //   document.body.appendChild(scriptElement);
    // }

    let url = UrlParser.parseActiveUrlWithCombiner();
    if (!(url in routes)) {
      window.location.hash = '#/404';
      url = UrlParser.parseActiveUrlWithCombiner();
    }
    const page = routes[url];
    this._content.innerHTML = await page.render();
    await page.afterRender();
  }
}

export default App;
