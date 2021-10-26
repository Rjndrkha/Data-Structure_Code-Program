const NotFound = {
  async render() {
    return `
          <div class="not__found-container">
              <h1 class="not__found-title">404</h1>
              <p class="not__found-desc">The resource requested could not be found on this server!</p>
          </div>
        `;
  },

  // eslint-disable-next-line no-empty-function
  async afterRender() {

  },
};

export default NotFound;
