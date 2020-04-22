var convertv2 = require('./mastodon_converter');

var opts = {};
opts.theme = "dark"
opts.header = true
opts.boosts = true;
opts.replies = true;
opts.userUrl = "https://octodon.social/users/fenwick67";
//opts.feedUrl = feedUrl;
opts.mastofeedUrl = "/apiv2/feed?userurl=https%3A%2F%2Foctodon.social%2Fusers%2Ffenwick67&theme=dark&size=100&header=true&replies=false&boosts=false";

const html_data = await convertv2(opts).data

document.getElementById("test").innerHTML = html_data