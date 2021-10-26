const assert = require('assert');

Feature('Liking Restaurants');

Before(({ I }) => {
  I.amOnPage('/#/favorite');
});

Scenario('showing empty liked restaurants', ({ I }) => {
  I.seeElement('#query');
  I.see('No favorite restaurant!', '.post-item__not__found');
});

Scenario('liking one restaurant and remove it', async ({ I }) => {
  I.see('No favorite restaurant!', '.post-item__not__found');

  I.amOnPage('/');

  I.seeElement(('.post-item__title a'));

  const firstRestaurant = locate('.post-item__title a').first();
  const firstRestaurantTitle = await I.grabTextFrom(firstRestaurant);
  I.click(firstRestaurant);

  I.seeElement('#likeButton');
  I.click('#likeButton');
  I.amOnPage('/#/favorite');
  I.seeElement('.post-item');
  const likedRestaurantTitle = await I.grabTextFrom('.post-item__title a');
  assert.strictEqual(firstRestaurantTitle, likedRestaurantTitle);
  I.seeElement('.post-item__title a');
  I.click('.post-item__title a');
  I.waitForElement('.category__item', 2); // wait for 2 second
  I.seeElement('.category__item');
  I.seeElement('#likeButton');
  I.click('#likeButton');
  I.amOnPage('/#/favorite');
  I.seeElement('#query');
  I.see('No favorite restaurant!', '.post-item__not__found');
});

Scenario('searching restaurants', async ({ I }) => {
  I.see('No favorite restaurant!', '.post-item__not__found');

  I.amOnPage('/');

  I.seeElement('.post-item__title a');

  const titles = [];

  for (let i = 1; i <= 3; i++) {
    I.click(locate('.post-item__title a').at(i));
    I.seeElement('#likeButton');
    I.click('#likeButton');
    titles.push(await I.grabTextFrom('.headline__title-detail'));
    I.amOnPage('/');
  }

  I.amOnPage('/#/favorite');
  I.seeElement('#query');

  const searchQuery = titles[1].substring(1, 3);
  const matchingRestaurants = titles.filter((title) => title.indexOf(searchQuery) !== -1);

  I.fillField('#query', searchQuery);
  I.pressKey('Enter');

  const visibleLikedRestaurants = await I.grabNumberOfVisibleElements('.post-item');
  assert.strictEqual(matchingRestaurants.length, visibleLikedRestaurants);

  matchingRestaurants.forEach(async (title, index) => {
    const visibleTitle = await (await I.grabTextFrom(locate('.post-item__title').at(index + 1))).toUpperCase();
    assert.strictEqual(title, visibleTitle);
  });
});
