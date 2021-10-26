import { createRestaurantItemTemplate } from '../../templates/template-creator';

class FavoriteRestaurantSearchView {
  getTemplate() {
    return `
          <section class="content">
              <div id="exploreRestaurant">
                  <div class="latest">
                    <h1 class="latest__label">Your Favorite Restaurants</h1>
                    <div class="input-group">
                      <i class="fa fa-search" aria-hidden="true"></i>
                      <input id="query" type="text" placeholder="Find favorite restaurant">
                    </div>
                    <div id="posts" class="posts">
                    </div>
                  </div>
              </div>   
          </section>
        `;
  }

  runWhenUserIsSearching(callback) {
    document.getElementById('query').addEventListener('change', (event) => {
      callback(event.target.value);
    });
  }

  showRestaurants(restaurants) {
    this.showFavoriteRestaurants(restaurants);
  }

  showFavoriteRestaurants(restaurants = []) {
    let html;
    if (restaurants.length) {
      html = restaurants.reduce((carry, restaurant) => carry.concat(createRestaurantItemTemplate(restaurant)), '');
    } else {
      html = this._getEmptyRestaurantTemplate();
    }

    document.getElementById('posts').innerHTML = html;

    document.getElementById('posts').dispatchEvent(new Event('posts:updated'));
  }

  _getEmptyRestaurantTemplate() {
    return '<h2 class="post-item__not__found posts__not__found">No favorite restaurant!</h2>';
  }
}

export default FavoriteRestaurantSearchView;
