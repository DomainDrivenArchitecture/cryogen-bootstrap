{% if disqus? %}
    <div id="disqus_thread"></div>
    <script type="text/javascript">
        var disqus_config = function () {
            this.page.url = "{{site-url}}{{uri}}";
            this.page.identifier = "{{post.title}}";
        };
        (function() {
            var dsq = document.createElement('script'); dsq.type = 'text/javascript'; dsq.async = true;
            dsq.src = '//{{disqus-shortname}}.disqus.com/embed.js';
            (document.getElementsByTagName('head')[0] || document.getElementsByTagName('body')[0]).appendChild(dsq);
        })();
    </script>
{% endif %}
